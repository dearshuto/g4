#include <g4/generators/g4_Types.h>

namespace g4 {

class IGeometryProvider
{
public:
    virtual ~IGeometryProvider() noexcept = default;

    virtual int GetVertexCount() const noexcept = 0;

    virtual void GetVertex(Vertex* pOutVertex, int index) const noexcept = 0;

    virtual int GetEdgeCount() const noexcept = 0;

    virtual void GetEdgeConnection(EdgeConnection* pOutEdgeConnection,
                                   int index) const noexcept = 0;
};

}  // namespace g4