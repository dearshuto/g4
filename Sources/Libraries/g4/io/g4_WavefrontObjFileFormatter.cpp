#include <g4/generators/g4_IMeshBuffer.h>
#include <g4/io/g4_WavefrontObjFileFormatter.h>

#include <fstream>

namespace g4::io {

void WavefrontObjFileFormatter::Export(const char* pFilePath,
                                       const IMeshBuffer* pMeshBuffer) noexcept
{
    std::ofstream ofstream{pFilePath};

    // 頂点
    for (auto index = 0; index < pMeshBufferi->GetVertexBuffer().size(); index += 3) {
        const auto vertex0 = pMeshBuffer->GetVertexBuffer()[index + 0];
        const auto vertex1 = pMeshBuffer->GetVertexBuffer()[index + 1];
        const auto vertex2 = pMeshBuffer->GetVertexBuffer()[index + 2];
        ofstream << "v " << vertex0 << " " << vertex1 << " " << vertex2 << std::endl;
    }

    // 面
    for (auto index = 0; index < pMeshBuffer->GetIndexBuffer().size(); index += 3) {
        const auto index0 = 1 + pMeshBuffer->GetIndexBuffer()[index + 0];
        const auto index1 = 1 + pMeshBuffer->GetIndexBuffer()[index + 1];
        const auto index2 = 1 + pMeshBuffer->GetIndexBuffer()[index + 2];
        ofstream << "f " << index0 << "// " << index1 << "// " << index2 << "//" << std::endl;
    }
}

}  // namespace g4::io