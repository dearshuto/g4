#include <g4/generators/g4_IMeshBuffer.h>

#include <vector>

namespace g4::util {

class VectorMeshBuffer : public g4::IMeshBuffer, public g4::IMesh
{
public:
    virtual void PushVertex(float x, float y, float z) noexcept override
    {
        m_VertexBuffer.push_back(x);
        m_VertexBuffer.push_back(y);
        m_VertexBuffer.push_back(z);
    }

    virtual void PushNormal(float x, float y, float z) noexcept override
    {
        m_NormalBuffer.push_back(x);
        m_NormalBuffer.push_back(y);
        m_NormalBuffer.push_back(z);
    }

    virtual void PushIndex(uint32_t index) noexcept override { m_IndexBuffer.push_back(index); }

    const auto& GetVertexBuffer() const noexcept { return m_VertexBuffer; }

    const auto& GetIndexBuffer() const noexcept { return m_IndexBuffer; }

    // IMesh -------------------------------------------------------------------
    int GetVertexCount() const noexcept { return static_cast<int>(m_VertexBuffer.size() / 3); }

    float GetX(int index) const noexcept { return m_VertexBuffer[3 * index + 0]; }

    float GetY(int index) const noexcept { return m_VertexBuffer[3 * index + 1]; }

    float GetZ(int index) const noexcept { return m_VertexBuffer[3 * index + 2]; }

    int GetIndexCount() const noexcept { return static_cast<int>(m_IndexBuffer.size()); }

    uint32_t GetIndex(int index) const noexcept { return m_IndexBuffer[index]; }
    //--------------------------------------------------------------------------

private:
    std::vector<float> m_VertexBuffer;
    std::vector<float> m_NormalBuffer;
    std::vector<uint32_t> m_IndexBuffer;
};

}  // namespace g4::util
