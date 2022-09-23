#ifndef g4_CgalMeshGenerator_h_
#define g4_CgalMeshGenerator_h_

#ifdef G4_HEADER_ONLY_MODE
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/IO/facets_in_complex_2_to_triangle_mesh.h>
#include <CGAL/IO/read_points.h>
#include <CGAL/Implicit_surface_3.h>
#include <CGAL/Poisson_reconstruction_function.h>
#include <CGAL/Polygon_mesh_processing/distance.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Polyhedron_traits_with_normals_3.h>
#include <CGAL/Surface_mesh_default_triangulation_3.h>
#include <CGAL/compute_average_spacing.h>
#include <CGAL/make_surface_mesh.h>
#include <CGAL/property_map.h>
#include <g4/generators/g4_IMeshBuffer.h>
#include <g4/generators/g4_Types.h>

#include <vector>
#endif

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

    void Generate(IMeshBuffer* pBuffer,
                  const Point* pVertexAndNormalBuffer,
                  int bufferLength) const noexcept
    {
        const auto generateParams =
            GenerateParams{}.SetPoints(pVertexAndNormalBuffer, bufferLength);
        Generate(pBuffer, generateParams);
    }

#ifdef G4_HEADER_ONLY_MODE
#include "../../../../Sources/Libraries/g4/generators/detail/g4_CgalMeshGenerator.cpp"
#else
    void Generate(IMeshBuffer* pBuffer, const GenerateParams& generateParams) const noexcept;
#endif
};

}}}  // namespace g4::generators::detail

#endif
