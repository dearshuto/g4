namespace g4::util {
class LinearInterpolator;
}

extern "C" g4::util::LinearInterpolator* CreateLinearInterpolator() noexcept;

extern "C" void DestroyLinearInterpolator(g4::util::LinearInterpolator* pInstance) noexcept;
