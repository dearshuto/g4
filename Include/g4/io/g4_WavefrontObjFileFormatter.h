#ifndef g4_WavefronObjFileFormatter_H_
#define g4_WavefronObjFileFormatter_H_

namespace g4 {
class IMesh;
}

namespace g4::io {

class WavefrontObjFileFormatter final
{
public:
    void Export(const char* pFilePath, const IMesh* pMeshBuffer) noexcept;
};

}  // namespace g4::io

#endif
