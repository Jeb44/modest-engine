target_sources(modest-engine
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Console.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IConsolePrinter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/NullPrinter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/WinConsolePrinter.cpp
)


