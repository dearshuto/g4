#ifndef g4_FloatTypes_h_
#define g4_FloatTypes_h_

// EdgeConnection のインクルード用
// TODO: EdgeConnection の定義をこのヘッダに移動する
#include <g4/generators/g4_Types.h>

namespace g4 {

constexpr EdgeConnection MakeEdge(uint32_t v0, uint32_t v1) noexcept { return {v0, v1}; }

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
