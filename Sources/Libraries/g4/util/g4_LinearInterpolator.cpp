#ifndef G4_HEADER_ONLY_MODE
#include <g4/generators/g4_Types.h>
#include <g4/util/g4_LinearInterpolator.h>

#include <Eigen/Core>
#endif

#ifndef G4_HEADER_ONLY_MODE
// clang-format off
namespace g4 { namespace util {
// clang-format on
#endif

#ifdef G4_HEADER_ONLY_MODE
int Execute(InterpolatedVertex* pOutBuffer,
            int bufferLength,
            const Vertex& vertex0,
            const Vertex& vertex1) const noexcept
#else
int LinearInterpolator::Execute(InterpolatedVertex* pOutBuffer,
                                int bufferLength,
                                const Vertex& vertex0,
                                const Vertex& vertex1) const noexcept
#endif
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

#ifndef G4_HEADER_ONLY_MODE
// clang-format off
}}  // namespace g4::util
// clang-format on
#endif