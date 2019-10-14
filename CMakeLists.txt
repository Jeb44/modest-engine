# === MODEST_ENGINE === 
# => CMakeLists.txt

# Installation: https://cmake.org/download/ 
# download "cmake-3.14.3-win64-x64.msi"
# download make at http://gnuwin32.sourceforge.net/packages/make.htm

# cmd.exe: (cd to builds folder)
# cmake -G "MinGW Makefiles" ..
# mingw32-make
# ./modest-engine.exe

# Some useful links for CMake noobs (like me)
# https://gitlab.kitware.com/cmake/cmake/blob/master/Tests/Tutorial/Step1/CMakeLists.txt
# https://cmake.org/cmake-tutorial/
# https://preshing.com/20170511/how-to-build-a-cmake-based-project/
# https://www.johnlamp.net/cmake-tutorial-3-gui-tool.html

# SFML Helps
# cmake: https://github.com/SFML/SFML/blob/master/cmake/SFMLConfig.cmake.in (forum: https://en.sfml-dev.org/forums/index.php?topic=24070.0)
# example code: file:///C:/Users/gabri/Documents/GitHub/modest-engine/SFML-2.5.1/doc/html/index.html

# todo: version number in project() ?
# todo: c++11 okay this way with variables?

cmake_minimum_required (VERSION 3.3 FATAL_ERROR)
project(modest-engine
	VERSION 0.1.2
	DESCRIPTION "CMake root for modest-engine"
	HOMEPAGE_URL "https://github.com/Natschu/modest-engine"
)

# c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED  True)
set(SFML_STATIC_LIBRARIES TRUE)

# Link standard c++ library staticly to the programm
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

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

# add the executable
add_executable(modest-engine engine/main.cpp)

# add subdirectories
list (APPEND EXTRA_INCLUDES "")

include_directories(
	${PROJECT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/engine/include
)
add_subdirectory(${PROJECT_SOURCE_DIR}/engine)

# configure a header file to pass some of the CMake setting to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/meConfig.h.in"
	"${PROJECT_BINARY_DIR}/meConfig.h"
)

# target_link_libraries(modest_engine ${EXTRA_LIBS})

# add the binary tree to the search path for include files so that we will find "meConfig.h"
# this has to be placed AFTER add_executable & find_package
target_include_directories(	modest-engine PUBLIC
							"${PROJECT_BINARY_DIR}"
							${EXTRA_INCLUDES}
)

# SFML
target_link_libraries(SFMLTest sfml-graphics sfml-audio)

# see builds/CMakeCache.txt to view it unter "internal"
set(CONFIGURED_ONCE TRUE CACHE INTERNAL 
	"A flag showing that CMake has configure at least once.")

