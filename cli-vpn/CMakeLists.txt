cmake_minimum_required(VERSION 3.5)

project(GUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(gui/include)
include_directories(gui/src)
include_directories(gui/conf)

include_directories(handshake/headers)
include_directories(handshake/src)

include_directories(logic/include)
include_directories(logic/src)

set(PROJECT_SOURCES
     #GUI
     gui/src/main.cpp
     gui/src/mainwindow.cpp
     gui/include/mainwindow.h
     gui/src/mainwindow.ui

     gui/src/configurationwindow.cpp
     gui/include/configurationwindow.h
     gui/src/configurationwindow.ui

     gui/include/countries.h
     gui/src/countries.cpp
     gui/src/countries.ui

     gui/conf/configuration.txt

     gui/resource.qrc

     #Client Back Headers
     logic/include/ConfigClient.hpp
     logic/include/Parser.hpp
     logic/include/VPNClient.hpp
     logic/include/vpnTunnel.hpp
     handshake/headers/ClinetHandshake.hpp
     handshake/headers/DnsRequest.hpp
     #Client Back Source
     logic/src/ConfigClient.cpp
     logic/src/VPNClient.cpp
     logic/src/Parser.cpp
     handshake/src/ClientHandshake.cpp
     handshake/src/DnsRequest.cpp
     )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GUI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET RK2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(GUI SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(GUI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(GUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core)

set_target_properties(GUI PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

install(TARGETS GUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GUI)
endif()
