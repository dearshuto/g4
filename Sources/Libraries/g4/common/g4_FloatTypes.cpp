#include <g4/common/g4_FloatTypes.h>

#include <type_traits>

namespace g4 {

static_assert(std::is_standard_layout<Float4>::value);
static_assert(std::is_trivially_copyable<Float4>::value);

}  // namespace g4
