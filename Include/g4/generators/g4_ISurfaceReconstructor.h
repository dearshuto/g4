#ifndef g4_ISurfaceReconstructor_H_
#define g4_ISurfaceReconstructor_H_

namespace g4 {
struct Point;
struct IMeshBuffer;
}  // namespace g4

namespace g4::generators {

class ISurfaceReconstructor
{
public:
    class ReconstructParams
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
    virtual ~ISurfaceReconstructor() noexcept = default;

    virtual void Reconstruct(IMeshBuffer* pOutBuffer,
                             const ReconstructParams& reconstructParams) const noexcept = 0;
};

}  // namespace g4::generators

#endif
