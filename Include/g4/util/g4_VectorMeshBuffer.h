#include <g4/generators/g4_IMeshBuffer.h>

#include <vector>

namespace g4::util {

class VectorMeshBuffer : public g4::IMeshBuffer
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

private:
    std::vector<float> m_VertexBuffer;
    std::vector<float> m_NormalBuffer;
    std::vector<uint32_t> m_IndexBuffer;
};

}  // namespace g4::util
