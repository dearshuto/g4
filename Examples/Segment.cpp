#include <g4/generators/g4_Generator.h>
#include <g4/generators/g4_IGeometryProvider.h>
#include <g4/generators/g4_IMeshBuffer.h>
#include <g4/generators/g4_IMeshProvider.h>
#include <g4/io/g4_WavefrontObjFileFormatter.h>
#include <g4/util/g4_VectorMeshBuffer.h>

#include <iostream>

class SegmentProvider : public g4::IGeometryProvider
{
public:
    virtual ~SegmentProvider() noexcept = default;

    virtual int GetVertexCount() const noexcept override { return 2; }

    virtual void GetVertex(g4::Vertex* pOutVertex, int index) const noexcept override
    {
        pOutVertex->x = index == 0 ? 0.0f : 1.0f;
        pOutVertex->y = 0.0f;
        pOutVertex->z = 0.0f;
    }

    virtual int GetEdgeCount() const noexcept override { return 1; }

    virtual void GetEdgeConnection(g4::EdgeConnection* pOutEdgeConnection,
                                   int index) const noexcept override
    {
        pOutEdgeConnection->index0 = 0;
        pOutEdgeConnection->index1 = 1;
    }
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
    fileFormatter.Export("test.obj", &meshBuffer);

    return EXIT_SUCCESS;
}
