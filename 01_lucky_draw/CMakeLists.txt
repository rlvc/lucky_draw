cmake_minimum_required(VERSION 3.10)
project(lucky_draw)
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB LUCKY_DRAW_FILE "${PROJECT_SOURCE_DIR}/draw.h" "${PROJECT_SOURCE_DIR}/draw.cc")

message("LUCKY_DRAW_FILE: ${LUCKY_DRAW_FILE}")

add_library(lucky_draw SHARED ${LUCKY_DRAW_FILE})
set(GOOGLETEST_LIBRARIES gmock gtest)
set(GOOGLETEST_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/googletest-distribution/include)
set(GOOGLETEST_LIBRARIES_DIRS ${PROJECT_SOURCE_DIR}/googletest-distribution/lib)
 foreach(_lib ${GOOGLETEST_LIBRARIES})

    add_library(${_lib} STATIC IMPORTED GLOBAL)

	set_target_properties(${_lib} PROPERTIES
	    IMPORTED_IMPLIB_DEBUG "${GOOGLETEST_LIBRARIES_DIRS}/${_lib}d.lib"
	    IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG ""
	    IMPORTED_LOCATION_DEBUG "${GOOGLETEST_LIBRARIES_DIRS}/${_lib}d.lib"
	)

	set_target_properties(${_lib} PROPERTIES
	    IMPORTED_IMPLIB_RELEASE "${GOOGLETEST_LIBRARIES_DIRS}/${_lib}.lib"
	    IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE ""
	    IMPORTED_LOCATION_RELEASE "${GOOGLETEST_LIBRARIES_DIRS}/${_lib}.lib"
	)
  
endforeach()
include_directories(${GOOGLETEST_INCLUDE_DIRS})
message("GOOGLETEST_INCLUDE_DIRS: ${GOOGLETEST_INCLUDE_DIRS}")

file(GLOB TEST_SOURCES "draw_gtest.cpp")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
 
add_executable(lucky_draw_test ${TEST_SOURCES})

target_link_libraries(lucky_draw_test
                      lucky_draw
                      ${GOOGLETEST_LIBRARIES}
                      )