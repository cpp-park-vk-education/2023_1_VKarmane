cmake_minimum_required(VERSION 3.10)
project(Server)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_subdirectory(googletest)
add_executable(Server test.cpp)
target_link_libraries(Server gtest_main)

include_directories(include)