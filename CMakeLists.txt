# === MODEST_ENGINE === 
# => CMakeLists.txt

# todo: version number in project() ?
# todo: c++11 okay this way with variables?

cmake_minimum_required (VERSION 3.9 FATAL_ERROR)
project(modest-engine
	VERSION 0.1.2
	DESCRIPTION "CMake root for modest-engine"
	HOMEPAGE_URL "https://github.com/Natschu/modest-engine"
)

include(cmake/IPO.cmake)
enable_IPO(modest-engine)

include(cmake/Doxygen.cmake)
enable_doxygen()

add_library(project_options INTERFACE)
add_library(project_warnings INTERFACE)

target_compile_features(project_options INTERFACE cxx_std_17)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++")

find_package(SFML 2.5.1 COMPONENTS graphics window audio network system REQUIRED PATHS ${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML)

# enable warnings for GNU 
include(cmake/Doxygen.cmake)
set_project_warnings(project_warnings)

include (cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# if ("${CMAKE_CXX_COMPLIER_ID}" STREQUAL "GNU")
# 	set (warnings "-Wall -Wextra -Werror")
# 	if (NOT CONFIGURED_ONCE)
# 		set (CMAKE_CXX_FLAGS "${warnings}"
# 			CACHE STRING "Flags used by the compiler during all build types." FORCE)
# 		set (CMAKE_C_FLAGS "${warnings}"
# 			CACHE STRING "Flags used by the compiler during all build types." FORCE)
# 	endif()
# endif()

# add the executable
add_executable(modest-engine engine/main.cpp)

# add subdirectories
list (APPEND EXTRA_INCLUDES "")

include_directories(
	${PROJECT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/engine/include
	${PROJECT_SOURCE_DIR}/SFML-2.5.1/include
)
add_subdirectory(${PROJECT_SOURCE_DIR}/engine)

# configure a header file to pass some of the CMake setting to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/meConfig.h.in"
	"${PROJECT_BINARY_DIR}/meConfig.h"
)

# add the binary tree to the search path for include files so that we will find "meConfig.h"
# this has to be placed AFTER add_executable & find_package
target_include_directories(	modest-engine PUBLIC
							"${PROJECT_BINARY_DIR}"
							${EXTRA_INCLUDES}
)

target_link_libraries(modest-engine sfml-graphics sfml-window sfml-audio sfml-network sfml-system)

# see builds/CMakeCache.txt to view it unter "internal"
set(CONFIGURED_ONCE TRUE CACHE INTERNAL "A flag showing that CMake has configure at least once.")

