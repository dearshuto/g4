namespace g4 {
class Generator;
class IMeshBuffer;
class IGeometryProvider;
class IInterpolator;
class IPointGenerator;
}  // namespace g4

extern "C" g4::Generator* CreateGenerator() noexcept;

extern "C" void DestroyGenerator(g4::Generator* addr) noexcept;

extern "C" void Execute(g4::Generator* pInstance,
                        g4::IMeshBuffer* pMeshBuffer,
                        const g4::IGeometryProvider* pGeometryProvider,
                        const g4::IInterpolator* pInterpolator,
                        const g4::IPointGenerator* pPointGenerator) noexcept;