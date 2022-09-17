#ifndef g4_IMeshProvider_h
#define g4_IMeshProvider_h

#include <cstdint>

namespace g4 {

struct EdgeConnection
{
    uint32_t index0;
    uint32_t index1;
};

struct Vertex
{
    float x;
    float y;
    float z;
};

class IMeshProvider
{
public:
    virtual~IMeshProvider() noexcept = default;
    
    virtual int GetVertexCount() const noexcept = 0;
    
    virtual void GetVertex(Vertex* pOutVertex, int index) const noexcept = 0;
    
    virtual int GetEdgeCount() const noexcept = 0;
    
    virtual void GetEdgeConnection(EdgeConnection* pOutEdgeConnection, int index) const noexcept = 0;
};

}

#endif /* g4_IMeshProvider_h */
