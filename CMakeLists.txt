cmake_minimum_required(VERSION 3.16)

project(ElaFramework VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# 设置Qt相关的CMake策略
if(POLICY CMP0071)
    cmake_policy(SET CMP0071 NEW)
endif()
if(POLICY CMP0087)
    cmake_policy(SET CMP0087 NEW)
endif()

#在这里配置QT路径 例如 C:/Qt/6.8.3/msvc2022_64
#SET(QT_SDK_DIR C:/Qt/6.8.3/msvc2022_64 CACHE PATH "QT SDK DIR" FORCE)
SET(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/Install CACHE PATH "Installation path" FORCE)

option(BUILD_ELAPACKETIO "Build ElaPacketIO" OFF)
#list(APPEND CMAKE_PREFIX_PATH ${QT_SDK_DIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_subdirectory(ElaWidgetTools)
if (WIN32 AND BUILD_ELAPACKETIO)
    add_definitions(-DBUILD_WITH_ELAPACKETIO)
    add_subdirectory(ElaPacketIO)
endif ()
add_subdirectory(ElaWidgetToolsExample)

if (${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ElaWidgetTools)
endif ()
