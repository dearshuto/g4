#include <Eigen/Core>
#include <CGAL/poisson_surface_reconstruction.h>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Surface_mesh_default_triangulation_3.h>
#include <CGAL/make_surface_mesh.h>
#include <CGAL/Implicit_surface_3.h>
#include <CGAL/IO/facets_in_complex_2_to_triangle_mesh.h>
#include <CGAL/Poisson_reconstruction_function.h>
#include <CGAL/property_map.h>
#include <CGAL/IO/read_points.h>
#include <CGAL/compute_average_spacing.h>
#include <CGAL/Polygon_mesh_processing/distance.h>

#include <g4/generators/g4_Generator.h>
#include <g4/generators/g4_IMeshProvider.h>

namespace g4
{

void Generator::Execute(const IMeshProvider *pMeshProvider) const noexcept
{
    
}

}
