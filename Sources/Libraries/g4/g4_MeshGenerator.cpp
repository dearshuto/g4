#include <g4/generators/g4_Generator.h>
#include <g4/generators/g4_IGeometryProvider.h>
#include <g4/generators/g4_IMeshBuffer.h>
#include <g4/generators/g4_IMeshProvider.h>
#include <g4/util/g4_LinearInterpolator.h>
#include <g4/util/g4_SimplePointGenerator.h>

#include <Eigen/Core>
#include <array>
#include <iostream>
#include <span>
#include <vector>

namespace g4 {

void Generator::Execute([[maybe_unused]] const IMeshProvider* pMeshProvider) const noexcept {}

void Generator::Execute(IMeshBuffer* pBuffer,
                        const IGeometryProvider* pGeometryProvider) const noexcept
{
    g4::util::LinearInterpolator interpolator;
    g4::util::SimplePointGenerator pointGenerator;
    Execute(pBuffer, pGeometryProvider, &interpolator, &pointGenerator);
}

void Generator::Execute(IMeshBuffer* pBuffer,
                        const IGeometryProvider* pGeometryProvider,
                        const IInterpolator* pInterpolator,
                        const IPointGenerator* pPointGenerator) const noexcept
{
    Vertex begin;
    Vertex end;
    pGeometryProvider->GetVertex(&begin, 0);
    pGeometryProvider->GetVertex(&end, 1);

    // ジオメトリ情報
    std::vector<Point> vn;

    // 端点
    // {
    //     const auto beginNormalVector = Eigen::Vector3f{
    //         begin.x - end.x,
    //         begin.y - end.y,
    //         begin.z - end.z,
    //     };
    //     const auto normalizedBeginNormalVector = beginNormalVector.normalized();

    //     const auto endNormalVector = Eigen::Vector3f{
    //         end.x - begin.x,
    //         end.y - begin.y,
    //         end.z - begin.z,
    //     };
    //     const auto normalizedEndNormalVector = endNormalVector.normalized();

    //     Vertex beginNormal;
    //     beginNormal.x = normalizedBeginNormalVector.x();
    //     beginNormal.y = normalizedBeginNormalVector.y();
    //     beginNormal.z = normalizedBeginNormalVector.z();

    //     Vertex endNormal;
    //     endNormal.x = normalizedEndNormalVector.x();
    //     endNormal.y = normalizedEndNormalVector.y();
    //     endNormal.z = normalizedEndNormalVector.z();

    //     vn.push_back(std::make_pair(begin, beginNormal));
    //     vn.push_back(std::make_pair(end, endNormal));
    // }

    // 頂点
    {
        std::array<InterpolatedVertex, 32> vertexBuffer = {};
        const auto vertexCount                          = pInterpolator->Execute(
                                     vertexBuffer.data(), static_cast<int>(vertexBuffer.size()), begin, end);

        // ポイントの生成
        for (auto index = 0; index < vertexCount; ++index) {
            const auto& vertex                = vertexBuffer[index];
            std::array<Point, 64> pointBuffer = {};

            const auto pointCount =
                pPointGenerator->Generate(pointBuffer.data(), static_cast<int>(pointBuffer.size()),
                                          vertex.position, Vertex{1.0f, 0.0f, 0.0f});
            for (auto pointIndex = 0; pointIndex < pointCount; ++pointIndex) {
                vn.push_back(pointBuffer[pointIndex]);
            }
        }
    }

    m_Generator.Generate(pBuffer, vn.data(), static_cast<int>(vn.size()));
}

}  // namespace g4
