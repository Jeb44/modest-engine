# Add directory to target_include_directories
list (APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/engine/src")

# Add files to target_sources here:
# ...

# Add another sub_directory (which calls another CMakeLists.txt)
add_subdirectory(${PROJECT_SOURCE_DIR}/engine/src/core)
add_subdirectory(${PROJECT_SOURCE_DIR}/engine/src/common)