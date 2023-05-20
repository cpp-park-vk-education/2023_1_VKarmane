cmake_minimum_required(VERSION 3.10)
project(Server)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
#add_subdirectory(googletest)
add_executable(Server 
               src/config.cpp
               src/server.cpp
               src/VpnWorker.cpp
               src/main.cpp)

#target_link_libraries(Server gtest_main)

find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(Server ${Boost_LIBRARIES})

include_directories(include)

#add_subdirectory(tests)

# Test

add_subdirectory(googletest)
add_executable(ServerTest 
               tests/testConfig.cpp
               src/config.cpp 
               src/server.cpp
               src/VpnWorker.cpp)

target_link_libraries(ServerTest gtest_main ${Boost_LIBRARIES})
include(GoogleTest)
gtest_discover_tests(ServerTest)