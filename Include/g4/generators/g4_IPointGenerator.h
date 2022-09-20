#ifndef g4_IPointGenerator_h_
#define g4_IPointGenerator_h_

#include <tuple>

namespace g4 {

struct Point;
struct Vertex;

class IPointGenerator
{
public:
    virtual ~IPointGenerator() noexcept = default;
    
    virtual int Generate(Point* pOutBuffer,
                         int bufferLength,
                         const Vertex& vertex,
                         const Vertex& gradient) const noexcept = 0;
};

}  // namespace g4

#endif
