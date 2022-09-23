#include <g4/generators/g4_IMeshBuffer.h>
#include <g4/io/g4_WavefrontObjFileFormatter.h>

#include <fstream>

namespace g4::io {

void WavefrontObjFileFormatter::Export(const char* pFilePath, const IMesh* pMesh) noexcept
{
    std::ofstream ofstream{pFilePath};

    // 頂点
    for (auto index = 0; index < pMesh->GetVertexCount(); ++index) {
        const auto vertex0 = pMesh->GetX(index);
        const auto vertex1 = pMesh->GetY(index);
        const auto vertex2 = pMesh->GetZ(index);
        ofstream << "v " << vertex0 << " " << vertex1 << " " << vertex2 << std::endl;
    }

    // 面
    for (auto index = 0; index < pMesh->GetIndexCount(); index += 3) {
        const auto index0 = 1 + pMesh->GetIndex(index + 0);
        const auto index1 = 1 + pMesh->GetIndex(index + 1);
        const auto index2 = 1 + pMesh->GetIndex(index + 2);
        ofstream << "f " << index0 << "// " << index1 << "// " << index2 << "//" << std::endl;
    }
}

}  // namespace g4::io
