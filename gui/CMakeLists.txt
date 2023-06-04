cmake_minimum_required(VERSION 3.5)

project(GUI_FoxTailVPN VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(include)
include_directories(src)

set(PROJECT_SOURCES
        src/main.cpp

	src/mainwindow.cpp
	include/mainwindow.h
	src/ui/mainwindow.ui

	src/configurationwindow.cpp
	include/configurationwindow.h
	src/ui/configurationwindow.ui

	include/countries.h
	src/countries.cpp
	src/ui/countries.ui

	conf/configuration.txt

	resource.qrc
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GUI_FoxTailVPN
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(GUI_FoxTailVPN SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(GUI_FoxTailVPN
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(GUI_FoxTailVPN PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(GUI_FoxTailVPN PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS GUI_FoxTailVPN
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GUI_FoxTailVPN)
endif()
