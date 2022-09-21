#include <g4/generators/detail/g4_CgalMeshGenerator.h>

namespace g4 {
class IMeshBuffer;
struct Point;
}  // namespace g4

namespace g4::generators {

class DirectGenerator
{
public:
    void Generate(IMeshBuffer* pMeshBuffer, const Point* pPoints, int pointCount) const noexcept;

private:
    detail::CgalMeshGenerator m_CgalMeshGenerator;
};

}  // namespace g4::generators
