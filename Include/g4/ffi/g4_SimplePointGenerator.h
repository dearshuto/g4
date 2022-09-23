namespace g4::util {
class SimplePointGenerator;
}

extern "C" g4::util::SimplePointGenerator* SimplePointGeneratorCreate() noexcept;

extern "C" void SimplePointGeneratorDestroy(g4::util::SimplePointGenerator* pInstance) noexcept;