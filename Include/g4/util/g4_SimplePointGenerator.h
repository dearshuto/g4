#ifndef g4_SimplePointGenerator_h_
#define g4_SimplePointGenerator_h_

#include <g4/generators/g4_IPointGenerator.h>

#ifdef G4_HEADER_ONLY_MODE
#include <g4/generators/g4_Types.h>
#include <g4/util/g4_SimplePointGenerator.h>

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <vector>
#endif

namespace g4 { namespace util {

class SimplePointGenerator final : public IPointGenerator
{
public:
    virtual ~SimplePointGenerator() noexcept = default;

#ifdef G4_HEADER_ONLY_MODE
#include "../../../../Sources/Libraries/g4/util/g4_SimplePointGenerator.cpp"
#else
    virtual int Generate(Point* pOutBuffer,
                         int bufferLength,
                         const Vertex& vertex,
                         const Vertex& gradient) const noexcept override;
#endif
};

}}  // namespace g4::util

#endif
