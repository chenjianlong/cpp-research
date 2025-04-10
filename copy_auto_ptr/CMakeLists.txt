cmake_minimum_required(VERSION 3.15)
project(copy_auto_ptr)

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

set(SOURCE_FILES copy_auto_ptr.cpp)

add_executable(copy_auto_ptr ${SOURCE_FILES})
install(TARGETS copy_auto_ptr
	BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
