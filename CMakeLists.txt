cmake_minimum_required(VERSION 3.16)

project(lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(str_ops str_ops.cpp)
target_include_directories(str_ops PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(lab1 main.cpp)
target_link_libraries(lab1 PRIVATE str_ops)


add_executable(test_str_ops tests/test_str_ops.cpp)
target_link_libraries(test_str_ops PRIVATE str_ops GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_str_ops)