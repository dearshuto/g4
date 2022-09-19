#ifndef g4_Types_h_
#define g4_Types_h_

#include <cstdint>

namespace g4 {

struct EdgeConnection
{
    uint32_t index0;
    uint32_t index1;
};

struct Float3
{
    float x;
    float y;
    float z;
};

struct Vertex
{
    float x;
    float y;
    float z;
    float _padding;
};

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

}  // namespace g4

#endif
