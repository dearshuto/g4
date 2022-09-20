#ifndef g4_SimplePointGenerator_h_
#define g4_SimplePointGenerator_h_

#include <g4/generators/g4_IPointGenerator.h>

namespace g4 { namespace util {

class SimplePointGenerator final : public IPointGenerator
{
public:
    virtual ~SimplePointGenerator() noexcept = default;

    virtual int Generate(Point* pOutBuffer,
                         int bufferLength,
                         const Vertex& vertex,
                         const Vertex& gradient) const noexcept override;
};

}}  // namespace g4::util

#endif
