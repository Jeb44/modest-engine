# === MODEST_ENGINE === 
# => CMakeLists.txt

# Installation: https://cmake.org/download/ 
# download "cmake-3.14.3-win64-x64.msi"

# Some useful links for CMake noobs (like me)
# https://gitlab.kitware.com/cmake/cmake/blob/master/Tests/Tutorial/Step1/CMakeLists.txt
# https://cmake.org/cmake-tutorial/
# https://preshing.com/20170511/how-to-build-a-cmake-based-project/

cmake_minimum_required (VERSION 3.3)
project(modest_engine) # "m"odest-"e"ngine => ME

# c++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED  True)

# The version number
set (ME_VERSION_MAJOR 0)
set (ME_VERSION_MINOR 1)
set (ME_VERSION_PATCH 0)

# configure a header file to pass some of the CMake setting to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/meConfig.h.in"
	"${PROJECT_BINARY_DIR}/meConfig.h"
	)

# add the executable
add_executable(modest_engine engine/main.cpp)

# add the binary tree to the search path for include files so that we will find "meConfig.h"
# this has to be placed AFTER add_executable & find_package
target_include_directories(	modest_engine 
							PUBLIC 
							"${PROJECT_BINARY_DIR}")
#

