# add_library(engine NewClassTest.cpp)

list (APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/engine")

list (APPEND EXTRA_SOURCES engine/NewClassTest.cpp)

#add_subdirectory(subsystem)

#list (APPEND EXTRA_LIBS subsystem)
#list (APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/subsystem")