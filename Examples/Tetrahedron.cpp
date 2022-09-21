#include <g4/generators/g4_Generator.h>
#include <g4/generators/g4_IGeometryProvider.h>
#include <g4/generators/g4_IMeshBuffer.h>
#include <g4/generators/g4_IMeshProvider.h>

#include <array>
#include <fstream>
#include <iostream>
#include <vector>

class SegmentProvider : public g4::IGeometryProvider
{
public:
    virtual ~SegmentProvider() noexcept = default;

    virtual int GetVertexCount() const noexcept override
    {
        return static_cast<int>(m_Vertices.size());
    }

    virtual void GetVertex(g4::Vertex* pOutVertex, int index) const noexcept override
    {
        std::memcpy(pOutVertex, &m_Vertices[index], sizeof(g4::Vertex));
    }

    virtual int GetEdgeCount() const noexcept override
    {
        return static_cast<int>(m_EdgeConnections.size());
    }

    virtual void GetEdgeConnection(g4::EdgeConnection* pOutEdgeConnection,
                                   int index) const noexcept override
    {
        std::memcpy(pOutEdgeConnection, &m_EdgeConnections[index], sizeof(g4::EdgeConnection));
    }

private:
    std::array<g4::Vertex, 4> m_Vertices                = {{
                       {0.0f, 0.0f, 0.0f, 0.0f},
                       {1.0f, 0.0f, 0.0f, 0.0f},
                       {0.0f, 1.0f, 0.0f, 0.0f},
                       {0.0f, 0.0f, 1.0f, 0.0f},
    }};
    std::array<g4::EdgeConnection, 6> m_EdgeConnections = {{
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 2},
        {2, 3},
        {3, 1},
    }};
};

class MeshBuffer : public g4::IMeshBuffer
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

int main()
{
    MeshBuffer meshBuffer;
    SegmentProvider segmentProvider;
    [[maybe_unused]] g4::Generator generator;

    generator.Execute(&meshBuffer, &segmentProvider);

    std::cout << "Vertex Count: " << meshBuffer.GetVertexBuffer().size() << std::endl;
    std::cout << "Index Count: " << meshBuffer.GetIndexBuffer().size() << std::endl;

    std::ofstream ofstream{"tetrahedron.obj"};

    // 頂点
    for (auto index = 0; index < meshBuffer.GetVertexBuffer().size(); index += 3) {
        const auto vertex0 = meshBuffer.GetVertexBuffer()[index + 0];
        const auto vertex1 = meshBuffer.GetVertexBuffer()[index + 1];
        const auto vertex2 = meshBuffer.GetVertexBuffer()[index + 2];
        ofstream << "v " << vertex0 << " " << vertex1 << " " << vertex2 << std::endl;
    }

    // 面
    for (auto index = 0; index < meshBuffer.GetIndexBuffer().size(); index += 3) {
        const auto index0 = 1 + meshBuffer.GetIndexBuffer()[index + 0];
        const auto index1 = 1 + meshBuffer.GetIndexBuffer()[index + 1];
        const auto index2 = 1 + meshBuffer.GetIndexBuffer()[index + 2];
        ofstream << "f " << index0 << "// " << index1 << "// " << index2 << "//" << std::endl;
    }

    return EXIT_SUCCESS;
}
