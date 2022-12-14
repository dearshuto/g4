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
#include <g4/common/g4_DataTypes.h>
#include <g4/generators/g4_CgalSurfaceReconstructor.h>
#include <g4/generators/g4_IMeshBuffer.h>

#include <vector>

namespace g4 { namespace generators {

void CgalSurfaceReconstructor::Generate(IMeshBuffer* pBuffer,
                                        const Point* pVertexAndNormalBuffer,
                                        int bufferLength) const noexcept
{
    const auto generateParams = GenerateParams{}.SetPoints(pVertexAndNormalBuffer, bufferLength);
    Generate(pBuffer, generateParams);
}

void CgalSurfaceReconstructor::Generate(IMeshBuffer* pBuffer,
                                        const GenerateParams& generateParams) const noexcept
{
    const auto reconstructParams =
        ReconstructParams{}
            .SetAngle(generateParams.GetAngle())
            .SetPoints(generateParams.GetPoints(), generateParams.GetBufferLength())
            .SetRadius(generateParams.GetRadius())
            .SetDistance(generateParams.GetDistance());
    Reconstruct(pBuffer, reconstructParams);
}

void CgalSurfaceReconstructor::Reconstruct(
    IMeshBuffer* pBuffer, const ReconstructParams& reconstructParams) const noexcept
{
    using Kernel = CGAL::Exact_predicates_inexact_constructions_kernel;
    using FT     = Kernel::FT;
    using Point_map =
        CGAL::First_of_pair_property_map<std::pair<Kernel::Point_3, Kernel::Vector_3>>;
    using Normal_map =
        CGAL::Second_of_pair_property_map<std::pair<Kernel::Point_3, Kernel::Vector_3>>;
    using Surface_3 =
        CGAL::Implicit_surface_3<Kernel, CGAL::Poisson_reconstruction_function<Kernel>>;

    // Poisson options
    FT sm_angle = reconstructParams.GetAngle();  // Min triangle angle in degrees.
    FT sm_radius =
        reconstructParams.GetRadius();  // Max triangle size w.r.t. point set average spacing.
    FT sm_distance =
        reconstructParams
            .GetDistance();  // Surface Approximation error w.r.t. point set average spacing.

    const auto* pVertexAndNormalBuffer = reconstructParams.GetPoints();
    const auto bufferLength            = reconstructParams.GetBufferLength();
    std::vector<std::pair<Kernel::Point_3, Kernel::Vector_3>> v(bufferLength);
    std::transform(
        pVertexAndNormalBuffer, pVertexAndNormalBuffer + bufferLength, std::begin(v),
        [](const Point& point) {
            const auto position = Kernel::Point_3{point.vertex.x, point.vertex.y, point.vertex.z};
            const auto normal   = Kernel::Vector_3{point.normal.x, point.normal.y, point.normal.z};
            return std::make_pair(position, normal);
        });

    CGAL::Poisson_reconstruction_function<Kernel> function{v.begin(), v.end(), Point_map{},
                                                           Normal_map{}};
    function.compute_implicit_function();

    FT average_spacing = CGAL::compute_average_spacing<CGAL::Sequential_tag>(
        v, 6 /* knn = 1 ring */, CGAL::parameters::point_map(Point_map()));

    Kernel::Point_3 inner_point     = function.get_inner_point();
    Kernel::Sphere_3 boundingSphere = function.bounding_sphere();
    FT radius                       = std::sqrt(boundingSphere.squared_radius());

    // Defines the implicit surface: requires defining a
    // conservative bounding sphere centered at inner point.
    FT sm_sphere_radius = 5.0 * radius;
    FT sm_dichotomy_error =
        sm_distance * average_spacing / 1000.0;  // Dichotomy error must be << sm_distance
    Surface_3 surface(function, Kernel::Sphere_3(inner_point, sm_sphere_radius * sm_sphere_radius),
                      sm_dichotomy_error / sm_sphere_radius);

    // Defines surface mesh generation criteria
    CGAL::Surface_mesh_default_criteria_3<CGAL::Surface_mesh_default_triangulation_3> criteria(
        sm_angle,                        // Min triangle angle (degrees)
        sm_radius * average_spacing,     // Max triangle size
        sm_distance * average_spacing);  // Approximation error

    CGAL::Surface_mesh_default_triangulation_3 triangulation;
    CGAL::Surface_mesh_complex_2_in_triangulation_3<CGAL::Surface_mesh_default_triangulation_3>
        c2t3(triangulation);

    CGAL::make_surface_mesh(c2t3,                                 // reconstructed mesh
                            surface,                              // implicit surface
                            criteria,                             // meshing criteria
                            CGAL::Manifold_with_boundary_tag());  // require manifold mesh

    CGAL::Polyhedron_3<Kernel> outputMesh;
    CGAL::facets_in_complex_2_to_triangle_mesh(c2t3, outputMesh);

    // ??????
    for (const auto& vertex : outputMesh.vertex_handles()) {
        const auto& position = vertex->point();
        pBuffer->PushVertex(position.x(), position.y(), position.z());
    }

    // ???
    for (const auto& facet : outputMesh.facet_handles()) {
        CGAL_assertion(facet->is_triangle());

        auto iterator = facet->facet_begin();
        do {
            const auto vertexIndex = std::distance(outputMesh.vertices_begin(), iterator->vertex());
            pBuffer->PushIndex(vertexIndex);

        } while ((++iterator) != facet->facet_begin());
    }
}

}}  // namespace g4::generators
