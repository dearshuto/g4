PROJECT(g4)
cmake_minimum_required(VERSION 3.16)

# # 実行ファイルの出力ディレクトリの設定
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Outputs)

# # ライブラリファイルの出力ディレクトリの設定
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Libraries)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Libraries)
link_directories(${CMAKE_SOURCE_DIR}/Libraries)

# gtest
# SET(BUILD_GMOCK OFF CACHE BOOL "Use some expat option")
# SET(INSTALL_GTEST OFF CACHE BOOL "Use some expat option")
option(BUILD_GMOCK "" OFF)
option(INSTALL_GTEST "" OFF)
add_subdirectory(Externals/googletest)

# add_definitions(-DCGAL_EIGEN3_ENABLED)
add_library(g4 STATIC)
target_include_directories(g4
    PUBLIC ${CMAKE_SOURCE_DIR}/Include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/assert/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/array/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/algorithm/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/any/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/bimap/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/bind/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/config/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/container/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/container_hash/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/core/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/concept_check/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/detail/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/dynamic_bitset/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/foreach/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/fusion/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/format/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/graph/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/heap/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/iterator/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/intrusive/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/io/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/integer/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/lambda/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/lexical/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/mpl/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/move/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/math/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/mp11/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/multiprecision/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/multi_index/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/numeric/conversion/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/optional/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/parameter/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/property_map/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/predef/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/preprocessor/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/range/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/random/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/smart_ptr/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/static_assert/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/serialization/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/type_traits/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/tuple/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/throw_exception/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/type_index/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/utility/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/unordered/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/boost/variant/include/

    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/AABB_tree/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Algebraic_foundations/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Arithmetic_kernel/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/BGL/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Circulator/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Cartesian_kernel/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Distance_2/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Distance_3/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Poisson_surface_reconstruction_3/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Filtered_kernel/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Generator/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Homogeneous_kernel/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Hash_map/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/HalfedgeDS/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Installation/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Interval_support/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Intersections_2/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Intersections_3/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Profiling_tools/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Property_map/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Kernel_23/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Kernel_d/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Mesher_level/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Modular_arithmetic/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Modifier/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Number_types/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Point_set_processing_3/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Polyhedron/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Polygon_mesh_processing/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Principal_component_analysis_LGPL/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Random_numbers/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Spatial_sorting/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Spatial_searching/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Solver_interface/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Surface_mesher/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Stream_support/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/STL_Extension/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/TDS_3/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Triangulation_3/include
    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/cgal/Union_find/include

    PUBLIC ${CMAKE_SOURCE_DIR}/Externals/eigen/
)

target_compile_features(g4 PUBLIC cxx_std_20)

# ヘッダーオンリーモードの有効・無効を切り替えるオプション
option(G4_ENABLE_HEADER_ONLY_MODE "" OFF)

if(G4_ENABLE_HEADER_ONLY_MODE)
    message("Header only mode enabled")
    target_compile_definitions(g4
        PUBLIC G4_HEADER_ONLY_MODE
        PUBLIC CGAL_DISABLE_GMP
        PUBLIC CGAL_DISABLE_MPFR
    )
endif()

add_subdirectory(Examples)
add_subdirectory(Include)
add_subdirectory(Sources)
add_subdirectory(Tests)

get_target_property(G4_HEADERS g4 SOURCES)
list(FILTER G4_HEADERS INCLUDE REGEX "[.]h$")
source_group(
    TREE ${CMAKE_CURRENT_SOURCE_DIR}/Include
    PREFIX "Header Files"
    FILES ${G4_HEADERS}
)

get_target_property(G4_SOURCES g4 SOURCES)
list(FILTER G4_SOURCES INCLUDE REGEX "[.]cpp$")
source_group(
    TREE ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Libraries/
    PREFIX "Source Files"
    FILES ${G4_SOURCES}
)