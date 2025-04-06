cmake_minimum_required(VERSION 3.15)
project(prefer_nullptr)

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

set(SOURCE_FILES prefer_nullptr.cpp)

add_executable(prefer_nullptr ${SOURCE_FILES})
install(TARGETS prefer_nullptr
	BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
