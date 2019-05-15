# CMakeList.txt
# Add this directory to target_include_directories
list (APPEND EXTRA_INCLUDES "$\{PROJECT_SOURCE_DIR}/engine/src/common")

# Add files to target_sources here:
target_sources(modest-engine)
	PRIVATE
		$\{PROJECT_SOURCE_DIR}/engine/src/common/Locator.cpp
		$\{PROJECT_SOURCE_DIR}/engine/src/common/ConsoleCI.cpp
		$\{PROJECT_SOURCE_DIR}/engine/src/common/WinCommandPromptCI.cpp
)

# Add another sub_directory (which calls another CMakeLists.txt)
# add_subdirectory($\{PROJECT_SOURCE_DIR}/engine/src/common/...)