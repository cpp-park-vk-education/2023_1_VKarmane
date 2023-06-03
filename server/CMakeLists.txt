cmake_minimum_required(VERSION 3.10)
project(Server)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

# Главный исполняемый файл Server
add_executable(Server
               src/wireguardKey.cpp
               src/config.cpp
               src/server.cpp
               src/VpnWorker.cpp
               src/main.cpp)

# Поиск и подключение Boost
find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(Server ${Boost_LIBRARIES})

include_directories(include)

# Сборка и запуск тестов
add_executable(ServerTest 
               src/wireguardKey.cpp
               tests/testConfig.cpp
               src/config.cpp 
               src/server.cpp
               src/VpnWorker.cpp)

# Подключение Google Test
find_package(GTest REQUIRED)
target_link_libraries(ServerTest GTest::Main)

include(GoogleTest)
gtest_discover_tests(ServerTest)
