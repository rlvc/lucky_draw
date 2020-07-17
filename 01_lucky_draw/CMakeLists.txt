cmake_minimum_required(VERSION 3.10)
project(lucky_draw)

file(GLOB LUCKY_DRAW_FILE "${PROJECT_SOURCE_DIR}/draw.h" "${PROJECT_SOURCE_DIR}/draw.cc")
add_library(lucky_draw SHARED ${LUCKY_DRAW_FILE})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
message("GTEST_INCLUDE_DIRS: ${GTEST_INCLUDE_DIRS}")

file(GLOB TEST_SOURCES "draw_gtest.cpp")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
 
add_executable(lucky_draw_test ${TEST_SOURCES})

target_link_libraries(lucky_draw_test
                      lucky_draw
                      ${GTEST_LIBRARIES}
			pthread
                      )
