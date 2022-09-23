#include <g4/ffi/g4_IPointGenerator.h>
#include <g4/generators/g4_IPointGenerator.h>

int IPointGeneratorGenerate(g4::IPointGenerator* pPointGenerator,
                            g4::Point* pOutBuffer,
                            int bufferLength,
                            const g4::Vertex& vertex,
                            const g4::Vertex& gradient) noexcept
{
    return pPointGenerator->Generate(pOutBuffer, bufferLength, vertex, gradient);
}