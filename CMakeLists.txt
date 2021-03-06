cmake_minimum_required(VERSION 3.1)
project(KITSUNE_SCENEGRAPH)
enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(EnableTest "Enable unit testing" ON)

find_package(Bullet3 REQUIRED)
find_package(GLM REQUIRED)

if (EnableTest)
    # Check for boost test, but it is not required
    find_package(Boost 1.59 COMPONENTS unit_test_framework)
endif()
# SDL 2 isn't required. If found, build SDL module
find_package(SDL2)

if (NOT Boost_FOUND)
    message(AUTHOR_WARNING "boost test >= 1.59 not found, disabling unit testing!")
endif()

include_directories(${BULLET_INCLUDE_DIR})
set(LIBS ${LIBS} ${BULLET_LIBRARIES})

add_subdirectory(SceneGraph)

if (Boost_FOUND AND EnableTest)
    add_subdirectory(SceneGraph.Test)
endif()

if (SDL2_FOUND)
    add_subdirectory(glad)
    add_subdirectory(SceneGraph.SDL)
    add_subdirectory(SceneGraph.SDL.Example)
endif()
