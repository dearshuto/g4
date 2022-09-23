namespace g4 {
struct Point;
struct Vertex;
class IPointGenerator;
}  // namespace g4

extern "C" int IPointGeneratorGenerate(g4::IPointGenerator* pPointGenerator,
                                       g4::Point* pOutBuffer,
                                       int bufferLength,
                                       const g4::Vertex& vertex,
                                       const g4::Vertex& gradient) noexcept;