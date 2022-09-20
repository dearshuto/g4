#ifndef g4_CgalMeshGenerator_h_
#define g4_CgalMeshGenerator_h_

namespace g4 {
struct Point;
class IMeshBuffer;
}  // namespace g4

namespace g4 { namespace generators { namespace detail {

class CgalMeshGenerator final
{
public:
    CgalMeshGenerator() noexcept = default;

    ~CgalMeshGenerator() noexcept = default;

    void Generate(IMeshBuffer* pOutBuffer,
                  const Point* pVertexAndNormalBuffer,
                  int bufferLength) const noexcept;
};

}}}  // namespace g4::generators::detail

#endif
