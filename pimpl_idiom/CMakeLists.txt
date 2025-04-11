cmake_minimum_required(VERSION 3.15)
project(pimpl_idiom)

include_directories(
	${CMAKE_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
)

link_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_definitions(
	-g
)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
	widget.h
	widget.cpp
	main.cpp
)

add_executable(pimpl_idiom ${SOURCE_FILES})
install(TARGETS pimpl_idiom
	BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
