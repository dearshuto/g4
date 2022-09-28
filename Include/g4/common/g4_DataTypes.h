#ifndef g4_DataTypes_h_
#define g4_DataTypes_h_

#include <g4/common/g4_FloatTypes.h>

#include <cstdint>

namespace g4 {

struct Vertex : public Float3
{
};
constexpr Vertex MakeVertex(float x, float y, float z) noexcept { return {x, y, z}; }

struct Point
{
    Vertex vertex;
    Float3 normal;
};

struct InterpolatedVertex
{
    Vertex position;
    Float3 gradient;
};

struct EdgeConnection
{
    uint32_t index0;
    uint32_t index1;
};
constexpr EdgeConnection MakeEdge(uint32_t v0, uint32_t v1) noexcept { return {v0, v1}; }

}  // namespace g4

#endif
