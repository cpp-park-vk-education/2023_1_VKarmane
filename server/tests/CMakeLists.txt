cmake_minimum_required(VERSION 3.10)
project(Server)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_subdirectory(googletest)
add_executable(Server 
               testConfig.cpp 
               testServer.cpp 
               ../src/config.cpp 
               ../src/server.cpp
               ../src/VpnWorker.cpp)

find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(Server gtest_main ${Boost_LIBRARIES})

include_directories(../include)
