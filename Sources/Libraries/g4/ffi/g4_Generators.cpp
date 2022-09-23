#include <g4/ffi/g4_Generator.h>
#include <g4/generators/g4_Generator.h>

extern "C" void func() {}

g4::Generator* CreateGenerator() noexcept { return new g4::Generator{}; }

void DestroyGenerator(g4::Generator* addr) noexcept { delete addr; }

void Execute(g4::Generator* pInstance,
             g4::IMeshBuffer* pMeshBuffer,
             const g4::IGeometryProvider* pGeometryProvider,
             const g4::IInterpolator* pInterpolator,
             const g4::IPointGenerator* pPointGenerator) noexcept
{
    pInstance->Execute(pMeshBuffer, pGeometryProvider, pInterpolator, pPointGenerator);
}