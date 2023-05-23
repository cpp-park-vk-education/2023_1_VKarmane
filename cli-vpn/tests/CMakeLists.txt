cmake_minimum_required(VERSION 3.13)
project(ConfigClientTest LANGUAGES CXX)

# Enable C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Add GTest
add_subdirectory(googletest EXCLUDE_FROM_ALL)

# Add test executable and link against GTest and pthread libraries
add_executable(ConfigClientTest test.cpp)
target_link_libraries(ConfigClientTest PRIVATE gtest_main pthread)