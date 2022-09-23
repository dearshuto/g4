#include <g4/ffi/g4_LinearInterpolator.h>
#include <g4/util/g4_LinearInterpolator.h>

g4::util::LinearInterpolator* CreateLinearInterpolator() noexcept
{
    new g4::util::LinearInterpolator{};
}

void DestroyLinearInterpolator(g4::util::LinearInterpolator* pInstance) noexcept
{
    delete pInstance;
}
