# add_library(subsystem NewClass.cpp)

# target_sources(modest_engine PRIVATE engine/subsystem/NewClass.cpp)

list (APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/engine/subsystem")

list (APPEND EXTRA_SOURCES engine/subsystem/NewClass.cpp)