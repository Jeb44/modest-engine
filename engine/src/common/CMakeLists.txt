target_sources(modest-engine
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Helper.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Locator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/assert.cpp
)


add_subdirectory(console)
