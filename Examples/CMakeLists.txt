# find_package(GMP REQUIRED)

add_executable(cube_4d Cube4d.cpp)
target_include_directories(cube_4d PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Include)
target_include_directories(cube_4d PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Externals/Eigen)
target_link_libraries(cube_4d PUBLIC g4)

add_executable(sphere Sphere.cpp)
target_include_directories(sphere PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Include)
target_include_directories(sphere PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Externals/Eigen)
target_link_libraries(sphere PUBLIC g4)

add_executable(segment Segment.cpp)
target_include_directories(segment PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Include)
target_link_libraries(segment PUBLIC g4)

add_executable(tetrahedron Tetrahedron.cpp)
target_include_directories(tetrahedron PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Include)
target_link_libraries(tetrahedron PUBLIC g4)