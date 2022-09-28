#include <g4/generators/g4_Generator.h>
#include <g4/generators/g4_IGeometryProvider.h>
#include <g4/io/g4_WavefrontObjFileFormatter.h>
#include <g4/util/g4_VectorMeshBuffer.h>

#include <array>
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
                       g4::MakeVertex(0.0f, 0.0f, 0.0f),
                       g4::MakeVertex(1.0f, 0.0f, 0.0f),
                       g4::MakeVertex(0.0f, 1.0f, 0.0f),
                       g4::MakeVertex(0.0f, 0.0f, 1.0f),
    }};
    std::array<g4::EdgeConnection, 6> m_EdgeConnections = {{
        g4::MakeEdge(0, 1),
        g4::MakeEdge(0, 2),
        g4::MakeEdge(0, 3),
        g4::MakeEdge(1, 2),
        g4::MakeEdge(2, 3),
        g4::MakeEdge(3, 1),
    }};
};

int main()
{
    g4::util::VectorMeshBuffer meshBuffer;
    SegmentProvider segmentProvider;
    [[maybe_unused]] g4::Generator generator;

    generator.Execute(&meshBuffer, &segmentProvider);

    std::cout << "Vertex Count: " << meshBuffer.GetVertexBuffer().size() << std::endl;
    std::cout << "Index Count: " << meshBuffer.GetIndexBuffer().size() << std::endl;

    g4::io::WavefrontObjFileFormatter fileFormatter;
    fileFormatter.Export("tetrahedron.obj", &meshBuffer);

    return EXIT_SUCCESS;
}
