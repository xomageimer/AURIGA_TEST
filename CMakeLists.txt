cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME auriga_test)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} src/main.cpp src/mat4x4.cpp)
add_executable(test_func test/test.cpp src/mat4x4.cpp)

add_subdirectory("contrib/gtest"
                 "googletest")
target_link_libraries(test_func PRIVATE gtest gtest_main gmock)
target_include_directories(test_func PRIVATE src contrib)

set_target_properties( ${PROJECT_NAME} test_func PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wall;-Wextra;-Wpedantic;"
        )

include (CTest)
enable_testing()
add_test(tests test_func)