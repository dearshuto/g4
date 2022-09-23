namespace g4 {
struct InterpolatedVertex;
struct Vertex;
class IInterpolator;
}  // namespace g4

extern "C" void IInterpolatorExecute(g4::IInterpolator* pInstance,
                                     g4::InterpolatedVertex* pOutBuffer,
                                     int bufferLength,
                                     const g4::Vertex& vertex0,
                                     const g4::Vertex& vertex1) noexcept;