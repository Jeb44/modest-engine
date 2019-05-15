# Add directory to target_include_directories
list (APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/engine/src/core")

# Add files to target_sources here:
target_sources(modest-engine
	PRIVATE
		${PROJECT_SOURCE_DIR}/engine/src/core/GameWorldModule.cpp
)

