list (APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/engine/subsystem")

target_sources(modest_engine
	PRIVATE
		${PROJECT_SOURCE_DIR}/engine/subsystem/NewClass.cpp
)
