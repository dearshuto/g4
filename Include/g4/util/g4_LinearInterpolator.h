#ifndef g4_LinearInterpolator_h_
#define g4_LinearInterpolator_h_

#include <g4/generators/g4_IInterpolator.h>

namespace g4 { namespace util {

class LinearInterpolator final : public IInterpolator
{
public:
    virtual ~LinearInterpolator() noexcept = default;

    virtual int Execute(InterpolatedVertex* pOutBuffer,
                        int bufferLength,
                        const Vertex& vertex0,
                        const Vertex& vertex1) const noexcept override;
};

}}  // namespace g4::util

#endif