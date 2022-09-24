#ifndef g4_Generator_H_
#define g4_Generator_H_

namespace g4::generators {
class ISurfaceReconstructor;
}

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

    void Execute(IMeshBuffer* pBuffer,
                 const IGeometryProvider* pGeometryProvider,
                 const IInterpolator* pInterpolator,
                 const IPointGenerator* pPointGenerator,
                 const g4::generators::ISurfaceReconstructor* pSurfaceReconstructor) const noexcept;
};

}  // namespace g4

#endif
