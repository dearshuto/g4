target_sources(g4 PRIVATE
    g4_MeshGenerator.cpp
)

add_subdirectory(common)
add_subdirectory(io)
add_subdirectory(generators)
add_subdirectory(util)