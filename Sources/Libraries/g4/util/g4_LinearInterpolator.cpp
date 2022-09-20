#include <g4/generators/g4_Types.h>
#include <g4/util/g4_LinearInterpolator.h>

#include <Eigen/Core>

namespace g4 { namespace util {

int LinearInterpolator::Execute(InterpolatedVertex* pOutBuffer,
                                int bufferLength,
                                const Vertex& vertex0,
                                const Vertex& vertex1) const noexcept
{
    for (auto index = 0; index < bufferLength; ++index) {
        const auto begin    = Eigen::Vector3f{vertex0.x, vertex0.y, vertex0.z};
        const auto end      = Eigen::Vector3f{vertex1.x, vertex1.y, vertex1.z};
        const auto gradient = (end - begin).normalized();
        const auto t        = static_cast<float>(index + 1) / static_cast<float>(bufferLength + 1);
        const auto interpolatedPoint = (1.0f - t) * begin + t * end;

        const auto x = interpolatedPoint.x();
        const auto y = interpolatedPoint.y();
        const auto z = interpolatedPoint.z();

        pOutBuffer[index].position.x = x;
        pOutBuffer[index].position.y = y;
        pOutBuffer[index].position.z = z;

        pOutBuffer[index].gradient.x = gradient.x();
        pOutBuffer[index].gradient.y = gradient.y();
        pOutBuffer[index].gradient.z = gradient.z();
    }

    return bufferLength;
}

}}  // namespace g4::util
