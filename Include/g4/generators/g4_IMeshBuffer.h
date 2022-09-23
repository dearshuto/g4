#ifndef g4_IMeshBuffer_H_
#define g4_IMeshBuffer_H_

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

class IMesh
{
public:
    virtual ~IMesh() noexcept = default;

    virtual int GetVertexCount() const noexcept = 0;

    virtual float GetX(int index) const noexcept = 0;

    virtual float GetY(int index) const noexcept = 0;

    virtual float GetZ(int index) const noexcept = 0;

    virtual int GetIndexCount() const noexcept = 0;

    virtual uint32_t GetIndex(int index) const noexcept = 0;
};

}  // namespace g4

#endif
