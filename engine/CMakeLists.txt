target_sources(modest-engine
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)


add_subdirectory(include)
add_subdirectory(src)
