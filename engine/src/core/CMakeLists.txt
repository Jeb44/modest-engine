target_sources(modest-engine
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Engine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Entity.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IEntityComponent.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/RenderModule.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/System.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/TestComponent.cpp
)


add_subdirectory(components)
add_subdirectory(resource)
