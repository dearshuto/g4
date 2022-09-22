#include <g4/generators/g4_DirectGenerator.h>
#include <g4/generators/g4_Types.h>
#include <g4/io/g4_WavefrontObjFileFotmatter.h>
#include <g4/util/g4_VectorMeshBuffer.h>

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <iostream>

int main()
{
    g4::util::VectorMeshBuffer meshBuffer;
    g4::generators::DirectGenerator generator;

    constexpr auto radius = 1.0f;
    std::vector<g4::Point> points;
    points.push_back({{0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}});
    points.push_back({{0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}});
    points.push_back({{0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}});
    points.push_back({{0.0f, radius, 0.0f}, {0.0f, 1.0f, 0.0f}});
    points.push_back({{0.0f, -radius, 0.0f}, {0.0f, -1.0f, 0.0f}});

    constexpr auto div    = 20;
    constexpr auto subDiv = 20;
    for (auto j = 0; j < subDiv; ++j) {
        for (auto i = 1; i < div; ++i) {
            // 緯度：X 軸回転
            const auto angleV = M_PI * static_cast<float>(i) / div;
            const auto rotationV =
                Eigen::Quaternionf{Eigen::AngleAxisf(angleV, Eigen::Vector3f{1.0f, 0.0f, 0.0f})};

            // 経度：Y 軸回転
            const auto angleH = 2.0f * M_PI * static_cast<float>(j) / subDiv;
            const auto rotationH =
                Eigen::Quaternionf{Eigen::AngleAxisf(angleH, Eigen::Vector3f{0.0f, 1.0f, 0.0f})};

            const auto rotation       = rotationH * rotationV;
            const auto vector         = rotation * Eigen::Vector3f{0.0f, 1.0f, 0.0f};
            const g4::Vertex position = {radius * vector.x(), radius * vector.y(),
                                         radius * vector.z()};
            const g4::Float3 normal   = {vector.x(), vector.y(), vector.z()};
            points.push_back({position, normal});
        }
    }

    generator.Generate(&meshBuffer, points.data(), static_cast<int>(points.size()));

    std::cout << "Vertex Count: " << meshBuffer.GetVertexBuffer().size() << std::endl;
    std::cout << "Index Count: " << meshBuffer.GetIndexBuffer().size() << std::endl;

    g4::io::WavefrontObjFileFormatter fileWriter;
    fileWriter.Export("sphere.obj", &meshBuffer);

    return EXIT_SUCCESS;
}
