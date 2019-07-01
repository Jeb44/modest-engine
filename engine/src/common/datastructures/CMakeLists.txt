# CMakeList.txt
# Add this directory to target_include_directories
list (APPEND EXTRA_INCLUDES "$\{PROJECT_SOURCE_DIR}/engine/src/common/datastructures")

# Add files to target_sources here:
target_sources(modest-engine
	PRIVATE
		${PROJECT_SOURCE_DIR}/engine/src/common/datastructures/Array.cpp
)

# Add another sub_directory (which calls another CMakeLists.txt)