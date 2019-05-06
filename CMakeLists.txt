cmake_minimum_required (VERSION 3.3)
project(ME) # modest-engine

# c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STNDARD_REQUIRED True)

# The version number
set (ME_VERSION_MAJOR 1)
set (ME_VERSION_MINOR 0)
set (ME_VERSION_PATCH 0)

# configure a header file to pass some of the CMake setting to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/meConfig.h.in"
	"${PROJECT_BINARY_DIR}/meConfig.h"
	)

# add the executable
add_executable(ME engine/main.cpp)

# add the binary tree to the search path for include files so that we will find "meConfig.h"
# this has to be placed AFTER add_executable & find_package
target_include_directories(	ME 
							PUBLIC 
							"${PROJECT_BINARY_DIR}")
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )



