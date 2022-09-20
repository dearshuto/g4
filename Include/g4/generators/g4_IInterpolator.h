#ifndef g4_IInterpolator_h_
#define g4_IInterpolator_h_

#include <tuple>

namespace g4 {

struct InterpolatedVertex;

class IInterpolator
{
public:
    virtual ~IInterpolator() noexcept = default;

    virtual int Execute(InterpolatedVertex* pOutBuffer,
                        int bufferLength,
                        const Vertex& vertex0,
                        const Vertex& vertex1) const noexcept = 0;
};

}  // namespace g4

#endif