#include <g4/generators/g4_Types.h>
#include <g4/util/g4_SimplePointGenerator.h>

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <vector>

#ifndef G4_HEADER_ONLY_MODE
// clang-format off
namespace g4 { namespace util {
// clang-format on
#endif

#ifdef G4_HEADER_ONLY_MODE
int Generate(Point* pOutBuffer,
             int bufferLength,
             const Vertex& vertex,
             const Vertex& gradient) const noexcept
#else
int SimplePointGenerator::Generate(Point* pOutBuffer,
                                   int bufferLength,
                                   const Vertex& vertex,
                                   const Vertex& gradient) const noexcept
#endif
{
    const auto pointCount = bufferLength;
    std::vector<Eigen::Vector3f> normals;
    for (auto index = 0; index < pointCount; ++index) {
        const auto rotation = Eigen::Quaternionf::FromTwoVectors(
            Eigen::Vector3f{1.0f, 0.0f, 0.0f}, Eigen::Vector3f{gradient.x, gradient.y, gradient.z});
        const auto angle = static_cast<float>(index) * 2.0f * static_cast<float>(M_PI) /
                           static_cast<float>(pointCount);
        const auto localRotation =
            Eigen::Quaternionf{Eigen::AngleAxis(angle, Eigen::Vector3f{1.0f, 0.0f, 0.0f})};

        const auto initNormal = Eigen::Vector3f{0.0f, 1.0f, 0.0f};
        const auto normal     = rotation * localRotation * initNormal;

        normals.push_back(normal);
    }

    for (auto index = 0; index < normals.size(); ++index) {
        const auto& normal        = normals[index];
        const auto position       = Eigen::Vector3f{vertex.x, vertex.y, vertex.z};
        const auto positionOffset = 0.01f * normal;
        const auto p              = position + positionOffset;

        // 位置
        pOutBuffer[index].vertex.x = p.x();
        pOutBuffer[index].vertex.y = p.y();
        pOutBuffer[index].vertex.z = p.z();

        // 法線
        pOutBuffer[index].normal.x = normal.x();
        pOutBuffer[index].normal.y = normal.y();
        pOutBuffer[index].normal.z = normal.z();
    }

    return pointCount;
}

#ifndef G4_HEADER_ONLY_MODE
// clang-format off
}}  // namespace g4::util
// clang-format on
#endif