#include <g4/ffi/g4_SimplePointGenerator.h>
#include <g4/util/g4_SimplePointGenerator.h>

g4::util::SimplePointGenerator* SimplePointGeneratorCreate() noexcept
{
    return new g4::util::SimplePointGenerator{};
}

void SimplePointGeneratorDestroy(g4::util::SimplePointGenerator* pInstance) noexcept
{
    delete pInstance;
}