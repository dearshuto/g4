#ifndef g4_CgalMeshGenerator_h_
#define g4_CgalMeshGenerator_h_

namespace g4 {
struct Point;
class IMeshBuffer;
}  // namespace g4

namespace g4 { namespace generators { namespace detail {

class CgalMeshGenerator final
{
public:
    class GenerateParams
    {
    public:
        float GetAngle() const noexcept { return m_MinTriangleAngle; }

        auto& SetAngle(float angle) noexcept
        {
            m_MinTriangleAngle = angle;
            return *this;
        }

        float GetRadius() const noexcept { return m_Radius; }

        auto& SetRadius(float radius) noexcept
        {
            m_Radius = radius;
            return *this;
        }

        float GetDistance() const noexcept { return m_Distance; }

        auto& SetDistance(float distance) noexcept
        {
            m_Distance = distance;
            return *this;
        }

        int GetBufferLength() const noexcept { return m_BuffetrLength; }

        const Point* GetPoints() const noexcept { return m_pPoints; }

        auto& SetPoints(const Point* pPoints, int length) noexcept
        {
            m_pPoints       = pPoints;
            m_BuffetrLength = length;
            return *this;
        }

    private:
        float m_MinTriangleAngle = 20.0f;
        float m_Radius           = 30.0f;
        float m_Distance         = 0.375f;
        int m_BuffetrLength      = 0;
        const Point* m_pPoints   = nullptr;
    };

public:
    CgalMeshGenerator() noexcept = default;

    ~CgalMeshGenerator() noexcept = default;

    void Generate(IMeshBuffer* pOutBuffer,
                  const Point* pVertexAndNormalBuffer,
                  int bufferLength) const noexcept;

    void Generate(IMeshBuffer* pOutBuffer, const GenerateParams& generateParams) const noexcept;
};

}}}  // namespace g4::generators::detail

#endif
