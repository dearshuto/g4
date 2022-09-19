#include <g4/generators/g4_Types.h>
#include <g4/util/g4_SimplePointGenerator.h>

#include <Eigen/Core>
#include <Eigen/Dense>

namespace g4 { namespace util {

int SimplePointGenerator::Generate(Point* pOutBuffer,
                                   int bufferLength,
                                   const Vertex& vertex,
                                   const Vertex& gradient) const noexcept
{
    int pointCount = 0;

    const auto rotation = Eigen::Quaternionf::FromTwoVectors(
        Eigen::Vector3f{1.0f, 0.0f, 0.0f}, Eigen::Vector3f{gradient.x, gradient.y, gradient.z});
    [[maybe_unused]] const auto aa  = rotation.conjugate() * Eigen::Vector3f{};
    const Eigen::Vector3f normals[] = {
        rotation.conjugate() * (0.707 * Eigen::Vector3f{0.0f, 1.0f, 1.0f}),
        rotation.conjugate() * (0.707 * Eigen::Vector3f{0.0f, -1.0f, 1.0f}),
        rotation.conjugate() * (0.707 * Eigen::Vector3f{0.0f, 1.0f, -1.0f}),
        rotation.conjugate() * (0.707 * Eigen::Vector3f{0.0f, -1.0f, -1.0f}),
    };

    for (const auto& normal : normals) {
        for (int i = 0; i < 1; ++i) {
            const auto position       = Eigen::Vector3f{vertex.x, vertex.y, vertex.z};
            const auto positionOffset = 1.01f * static_cast<float>(i + 1) * normal;
            const auto p              = position + positionOffset;

            // 位置
            pOutBuffer[pointCount].vertex.x = p.x();
            pOutBuffer[pointCount].vertex.y = p.y();
            pOutBuffer[pointCount].vertex.z = p.z();

            // 法線
            pOutBuffer[pointCount].normal.x = normal.x();
            pOutBuffer[pointCount].normal.y = normal.y();
            pOutBuffer[pointCount].normal.z = normal.z();

            ++pointCount;
        }
    }

    return pointCount;
}

}}  // namespace g4::util
