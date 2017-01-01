cmake_minimum_required(VERSION 2.8.12)

project(cpp_snippet C CXX)

enable_testing()
include(CTest)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(CXX_FLAGS
 -Wall
 -Wextra
 -Werror
 -Wconversion
 -Wno-unused-parameter
 -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
 -Wshadow
 -Wwrite-strings
 -march=native
 -rdynamic
 )
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})
message(STATUS "PROJECT_SOURCE_DIR : " ${PROJECT_SOURCE_DIR})
string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

option(update_gtest_switch "Does update gtest git " OFF)
if(update_gtest_switch)
if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif()

include(./ext/DownloadProject.cmake)
download_project(PROJ                googletest
    GIT_REPOSITORY      https://github.com/google/googletest.git
    GIT_TAG             master
    ${UPDATE_DISCONNECTED_IF_AVAILABLE}
    )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
# if (CMAKE_VERSION VERSION_LESS 2.8.11)
include_directories(SYSTEM "${gtest_SOURCE_DIR}/include"
    "${gmock_SOURCE_DIR}/include")
message(STATUS "gtest_SOURCE_DIR : " ${gtest_SOURCE_DIR})
message(STATUS "gmock_SOURCE_DIR : " ${gmock_SOURCE_DIR})
# endif()

add_subdirectory(src)
# file(GLOB src_files src/*.cpp)
# add_library(${CMAKE_PROJECT_NAME} ${src_files})
# add_executable(${CMAKE_PROJECT_NAME} ${src_files})
# file(GLOB test_files test/*.cpp)
# add_executable(test_obj ${test_files})
# target_link_libraries(test_obj ${CMAKE_PROJECT_NAME} gtest gmock_main)
# add_subdirectory(src)
# Trivial example using gtest and gmock
# add_executable(example example.cpp)
# target_link_libraries(example gtest gmock_main)
# add_test(NAME test_case COMMAND test_obj --verbose)
