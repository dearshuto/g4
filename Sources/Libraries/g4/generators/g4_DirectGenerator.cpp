#include <g4/generators/g4_DirectGenerator.h>
#include <g4/generators/g4_IMeshBuffer.h>
#include <g4/generators/g4_Types.h>

namespace g4::generators {

void DirectGenerator::Generate(IMeshBuffer *pMeshBuffer,
                               const Point *pPoints,
                               int pointCount) const noexcept
{
    const auto generateParams = g4::generators::detail::CgalMeshGenerator::GenerateParams{}
                                    .SetAngle(3.141592f / 3.0f)
                                    .SetRadius(1.0f)
                                    .SetDistance(0.375f)
                                    .SetPoints(pPoints, pointCount);
    m_CgalMeshGenerator.Generate(pMeshBuffer, generateParams);
}

}  // namespace g4::generators
