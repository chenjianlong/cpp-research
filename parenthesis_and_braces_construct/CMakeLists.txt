cmake_minimum_required(VERSION 3.15)
project(parenthesis_and_braces_construct)

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

set(SOURCE_FILES parenthesis_and_braces_construct.cpp)

add_executable(parenthesis_and_braces_construct ${SOURCE_FILES})
install(TARGETS parenthesis_and_braces_construct
	BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
