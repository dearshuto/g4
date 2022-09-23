#ifndef g4_LinearInterpolator_h_
#define g4_LinearInterpolator_h_

#include <g4/generators/g4_IInterpolator.h>

#ifdef G4_HEADER_ONLY_MODE
#include <g4/generators/g4_Types.h>
#include <g4/util/g4_LinearInterpolator.h>

#include <Eigen/Core>
#endif

namespace g4 { namespace util {

class LinearInterpolator final : public IInterpolator
{
public:
    virtual ~LinearInterpolator() noexcept = default;

#ifdef G4_HEADER_ONLY_MODE
#include "../../../Sources/Libraries/g4/util/g4_LinearInterpolator.cpp"
#else
    virtual int Execute(InterpolatedVertex* pOutBuffer,
                        int bufferLength,
                        const Vertex& vertex0,
                        const Vertex& vertex1) const noexcept override;
#endif
};

}}  // namespace g4::util

#endif