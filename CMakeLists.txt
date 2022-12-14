cmake_minimum_required(VERSION 3.23)
project(ISRPO_lab5)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest-main)
#include googletest/include dir
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(ISRPO_lab5 main.cpp)
#Link with GoogleTest
target_link_libraries(ISRPO_lab5 gtest gtest_main)