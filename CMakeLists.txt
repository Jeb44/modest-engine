# === MODEST_ENGINE === 
# => CMakeLists.txt

# Installation: https://cmake.org/download/ 
# download "cmake-3.14.3-win64-x64.msi"
# download make at http://gnuwin32.sourceforge.net/packages/make.htm

# cmd.exe: (cd to builds folder)
# cmake -G "MinGW Makefiles" ..
# mingw32-make

# Some useful links for CMake noobs (like me)
# https://gitlab.kitware.com/cmake/cmake/blob/master/Tests/Tutorial/Step1/CMakeLists.txt
# https://cmake.org/cmake-tutorial/
# https://preshing.com/20170511/how-to-build-a-cmake-based-project/
# https://www.johnlamp.net/cmake-tutorial-3-gui-tool.html

cmake_minimum_required (VERSION 3.3 FATAL_ERROR)
project(modest_engine) # "m"odest-"e"ngine => ME

# The version number
set (ME_VERSION_MAJOR 0)
set (ME_VERSION_MINOR 1)
set (ME_VERSION_PATCH 0)

# c++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED  True)

# enable warnings for GNU 
if ("${CMAKE_CXX_COMPLIER_ID}" STREQUAL "GNU")
	set (warnings "-Wall -Wextra -Werror")
	if (NOT CONFIGURED_ONCE)
		set (CMAKE_CXX_FLAGS "${warnings}"
			CACHE STRING "Flags used by the compiler during all build types." FORCE)
		set (CMAKE_C_FLAGS "${warnings}"
			CACHE STRING "Flags used by the compiler during all build types." FORCE)
	endif()
endif()

# Link standard c++ library staticly to the programm
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")

# add -I with include paths by compiling (relative?)


add_executable(modest_engine engine/main.cpp)

# add subdirectories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(engine)
add_subdirectory(engine/subsystem)
list (APPEND EXTRA_LIBS engine)
list (APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/engine" "${PROJECT_SOURCE_DIR}/engine/subsystem")

# configure a header file to pass some of the CMake setting to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/meConfig.h.in"
	"${PROJECT_BINARY_DIR}/meConfig.h"
)

# add the executable
target_link_libraries(modest_engine ${EXTRA_LIBS})

# add the binary tree to the search path for include files so that we will find "meConfig.h"
# this has to be placed AFTER add_executable & find_package
# target_include_directories(	modest_engine  PUBLIC 
							# "${PROJECT_BINARY_DIR}"
# )
target_include_directories(	modest_engine PUBLIC
							"${PROJECT_BINARY_DIR}"
							${EXTRA_INCLUDES}
)

# see builds/CMakeCache.txt to view it unter "internal"
set(CONFIGURED_ONCE TRUE CACHE INTERNAL 
	"A flag showing that CMake has configure at least once.")

