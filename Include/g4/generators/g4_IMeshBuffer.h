#include <cstdint>

namespace g4 {

class IMeshBuffer
{
public:
    virtual ~IMeshBuffer() = default;

    virtual void PushVertex(float x, float y, float z) noexcept = 0;

    virtual void PushNormal(float x, float y, float z) noexcept = 0;

    virtual void PushIndex(uint32_t index) noexcept = 0;
};
}  // namespace g4