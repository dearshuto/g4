#include <g4/ffi/g4_IInterpolator.h>
#include <g4/generators/g4_IInterpolator.h>

extern "C" void IInterpolatorExecute(g4::IInterpolator* pInstance,
                                     g4::InterpolatedVertex* pOutBuffer,
                                     int bufferLength,
                                     const g4::Vertex& vertex0,
                                     const g4::Vertex& vertex1) noexcept
{
    pInstance->Execute(pOutBuffer, bufferLength, vertex0, vertex1);
}