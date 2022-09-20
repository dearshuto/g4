add_executable(g4Tests
    Main.cpp
    g4_LinearInterpolationTests.cpp
    g4_SimplePointGeneratorTests.cpp)
target_include_directories(g4Tests
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../Include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../Externals/googletest/googletest/include)
target_link_libraries(g4Tests PUBLIC g4 gtest)
