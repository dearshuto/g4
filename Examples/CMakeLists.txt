# find_package(GMP REQUIRED)

add_executable(segment Segment.cpp)
target_include_directories(segment PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Include)
target_link_libraries(segment PUBLIC g4)