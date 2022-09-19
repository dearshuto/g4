#ifndef g4_Generator_H_
#define g4_Generator_H_

namespace g4 {

class IMeshProvider;
class IGeometryProvider;
class IMeshBuffer;

class Generator
{
public:
    Generator() noexcept = default;

    ~Generator() noexcept = default;

    void Execute(const IMeshProvider* pMeshProvider) const noexcept;

    void Execute(IMeshBuffer* pBuffer, const IGeometryProvider* pGeometryProvider) const noexcept;
};

}  // namespace g4

#endif
