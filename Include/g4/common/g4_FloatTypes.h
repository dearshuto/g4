#ifndef g4_FloatTypes_h_
#define g4_FloatTypes_h_

namespace g4 {

struct Float3
{
    float x;
    float y;
    float z;
};
constexpr Float3 MakeFloat3(float x, float y, float z) noexcept { return {x, y, z}; }

struct Float4
{
    float x;
    float y;
    float z;
    float w;
};

constexpr Float4 MakeFloat4(float x, float y, float z, float w) noexcept { return {x, y, z, w}; }
}  // namespace g4

#endif
