list (APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/engine")

target_sources(modest_engine
	PRIVATE
		${PROJECT_SOURCE_DIR}/engine/NewClassTest.cpp
)

add_subdirectory(${PROJECT_SOURCE_DIR}/engine/subsystem)