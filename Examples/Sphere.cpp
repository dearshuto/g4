#include <g4/generators/g4_DirectGenerator.h>
#include <g4/generators/g4_Types.h>
#include <g4/util/g4_VectorMeshBuffer.h>

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <fstream>
#include <iostream>
#include <vector>

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

    std::ofstream ofstream{"sphere.obj"};

    // 頂点
    for (auto index = 0; index < meshBuffer.GetVertexBuffer().size(); index += 3) {
        const auto vertex0 = meshBuffer.GetVertexBuffer()[index + 0];
        const auto vertex1 = meshBuffer.GetVertexBuffer()[index + 1];
        const auto vertex2 = meshBuffer.GetVertexBuffer()[index + 2];
        ofstream << "v " << vertex0 << " " << vertex1 << " " << vertex2 << std::endl;
    }

    // 面
    for (auto index = 0; index < meshBuffer.GetIndexBuffer().size(); index += 3) {
        const auto index0 = 1 + meshBuffer.GetIndexBuffer()[index + 0];
        const auto index1 = 1 + meshBuffer.GetIndexBuffer()[index + 1];
        const auto index2 = 1 + meshBuffer.GetIndexBuffer()[index + 2];
        ofstream << "f " << index0 << "// " << index1 << "// " << index2 << "//" << std::endl;
    }

    return EXIT_SUCCESS;
}
