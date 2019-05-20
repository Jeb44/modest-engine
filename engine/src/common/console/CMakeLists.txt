# CMakeList.txt
# Add this directory to target_include_directories
list (APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/engine/src/common/console")

# Add files to target_sources here:
target_sources(modest-engine
	PRIVATE
		${PROJECT_SOURCE_DIR}/engine/src/common/console/Console.cpp
		${PROJECT_SOURCE_DIR}/engine/src/common/console/IConsolePrinter.cpp
		${PROJECT_SOURCE_DIR}/engine/src/common/console/WinConsolePrinter.cpp
		${PROJECT_SOURCE_DIR}/engine/src/common/console/NullPrinter.cpp
)

# Add another sub_directory (which calls another CMakeLists.txt)
# add_subdirectory($\{PROJECT_SOURCE_DIR}/engine/src/common/console/...)