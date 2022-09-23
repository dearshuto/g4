#include <g4/common/g4_FloatTypes.h>
#include <g4/generators/g4_Generator.h>
#include <g4/generators/g4_IGeometryProvider.h>
#include <g4/generators/g4_Types.h>
#include <g4/io/g4_WavefrontObjFileFotmatter.h>
#include <g4/util/g4_LinearInterpolator.h>
#include <g4/util/g4_SimplePointGenerator.h>
#include <g4/util/g4_VectorMeshBuffer.h>

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <array>
#include <iostream>

class Cube4dProvider : public g4::IGeometryProvider
{
public:
    virtual int GetVertexCount() const noexcept override
    {
        return static_cast<int>(s_Vertices.size());
    }

    virtual void GetVertex(g4::Vertex* pOutVertex, int index) const noexcept override
    {
        const auto position4d =
            Eigen::Vector4f{s_Vertices[index].x - 0.5f, s_Vertices[index].y - 0.5f,
                            s_Vertices[index].z - 0.5f, s_Vertices[index].w};
        auto matrix = Eigen::Matrix<float, 3, 4>();
        matrix << 1, 0, 0, position4d.x(), 0, 1, 0, position4d.y(), 0, 0, 1, position4d.z();
        const auto position3d = matrix * position4d;
        const auto vertex     = {position3d.x(), position3d.y(), position3d.z()};
        pOutVertex->x         = position3d.x();
        pOutVertex->y         = position3d.y();
        pOutVertex->z         = position3d.z();
    }

    virtual int GetEdgeCount() const noexcept override { return static_cast<int>(s_Edges.size()); }

    virtual void GetEdgeConnection(g4::EdgeConnection* pOutEdgeConnection,
                                   int index) const noexcept override
    {
        pOutEdgeConnection->index0 = s_Edges[index].index0;
        pOutEdgeConnection->index1 = s_Edges[index].index1;
    }

private:
    static constexpr std::array<g4::Float4, 16> s_Vertices = {
        // 3D
        g4::MakeFloat4(0.0f, 0.0f, 0.0f, 0.0f),
        g4::MakeFloat4(1.0f, 0.0f, 0.0f, 0.0f),
        g4::MakeFloat4(0.0f, 1.0f, 0.0f, 0.0f),
        g4::MakeFloat4(1.0f, 1.0f, 0.0f, 0.0f),
        g4::MakeFloat4(0.0f, 0.0f, 1.0f, 0.0f),
        g4::MakeFloat4(1.0f, 0.0f, 1.0f, 0.0f),
        g4::MakeFloat4(0.0f, 1.0f, 1.0f, 0.0f),
        g4::MakeFloat4(1.0f, 1.0f, 1.0f, 0.0f),

        // 4D
        g4::MakeFloat4(0.0f, 0.0f, 0.0f, 1.5f),
        g4::MakeFloat4(1.0f, 0.0f, 0.0f, 1.5f),
        g4::MakeFloat4(0.0f, 1.0f, 0.0f, 1.5f),
        g4::MakeFloat4(1.0f, 1.0f, 0.0f, 1.5f),
        g4::MakeFloat4(0.0f, 0.0f, 1.0f, 1.5f),
        g4::MakeFloat4(1.0f, 0.0f, 1.0f, 1.5f),
        g4::MakeFloat4(0.0f, 1.0f, 1.0f, 1.5f),
        g4::MakeFloat4(1.0f, 1.0f, 1.0f, 1.5f),
    };

    static constexpr std::array<g4::EdgeConnection, 32> s_Edges = {
        // 3D
        g4::MakeEdge(0, 1),
        g4::MakeEdge(0, 2),
        g4::MakeEdge(2, 3),
        g4::MakeEdge(1, 3),
        g4::MakeEdge(0, 4),
        g4::MakeEdge(1, 5),
        g4::MakeEdge(2, 6),
        g4::MakeEdge(3, 7),
        g4::MakeEdge(4, 5),
        g4::MakeEdge(4, 6),
        g4::MakeEdge(6, 7),
        g4::MakeEdge(5, 7),

        // 4D
        g4::MakeEdge(8, 9),
        g4::MakeEdge(8, 10),
        g4::MakeEdge(10, 11),
        g4::MakeEdge(9, 11),
        g4::MakeEdge(8, 12),
        g4::MakeEdge(9, 13),
        g4::MakeEdge(10, 14),
        g4::MakeEdge(11, 15),
        g4::MakeEdge(12, 13),
        g4::MakeEdge(12, 14),
        g4::MakeEdge(14, 15),
        g4::MakeEdge(13, 15),

        // 3D-4D
        g4::MakeEdge(0, 8),
        g4::MakeEdge(1, 9),
        g4::MakeEdge(2, 10),
        g4::MakeEdge(3, 11),
        g4::MakeEdge(4, 12),
        g4::MakeEdge(5, 13),
        g4::MakeEdge(6, 14),
        g4::MakeEdge(7, 15),
    };
};

int main()
{
    g4::util::LinearInterpolator interpolator;
    g4::util::SimplePointGenerator pointGenerator;
    g4::util::VectorMeshBuffer meshBuffer;
    Cube4dProvider geometryProvider;
    g4::Generator generator;
    generator.Execute(&meshBuffer, &geometryProvider, &interpolator, &pointGenerator);

    g4::io::WavefrontObjFileFormatter fileFotmatter;
    fileFotmatter.Export("cube_4d.obj", &meshBuffer);

    return EXIT_SUCCESS;
}
