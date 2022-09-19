#ifndef g4_Generator_H_
#define g4_Generator_H_

#include <g4/generators/detail/g4_CgalMeshGenerator.h>

namespace g4 {

class IMeshProvider;
class IGeometryProvider;
class IMeshBuffer;
class IInterpolator;
class IPointGenerator;

class Generator
{
public:
    Generator() noexcept = default;

    ~Generator() noexcept = default;

    void Execute(const IMeshProvider* pMeshProvider) const noexcept;

    void Execute(IMeshBuffer* pBuffer, const IGeometryProvider* pGeometryProvider) const noexcept;

    void Execute(IMeshBuffer* pBuffer,
                 const IGeometryProvider* pGeometryProvider,
                 const IInterpolator* pInterpolator,
                 const IPointGenerator* pPointGenerator) const noexcept;

private:
    g4::generators::detail::CgalMeshGenerator m_Generator;
};

}  // namespace g4

#endif
