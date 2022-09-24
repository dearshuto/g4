#include <g4/generators/g4_CgalSurfaceReconstructor.h>

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
    g4::generators::CgalSurfaceReconstructor m_CgalMeshGenerator;
};

}  // namespace g4::generators
