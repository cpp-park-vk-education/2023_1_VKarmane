cmake_minimum_required(VERSION 3.14)

project(TDD_GUI LANGUAGES CXX)

set(QT_VERSION_MAJOR 6)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(TDD_GUI
  main.cpp
  urlconfiguration.h
  urlconfiguration.cpp
  urlconfigurationtest.h
  urlconfigurationtest.cpp
  authorization.h
  authorization.cpp
  authorizationtest.h
  authorizationtest.cpp
  alltests.h
  alltests.cpp
)

target_link_libraries(TDD_GUI Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)

install(TARGETS TDD_GUI
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
