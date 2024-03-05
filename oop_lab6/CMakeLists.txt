cmake_minimum_required(VERSION 3.14)
project(oop_lab6)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB SOURCES ${INCLUDE_DIR}/*.hpp)
file(GLOB HEADERS ${SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)

enable_testing()
add_executable(${PROJECT_NAME}_test test/test.cpp ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME}_test gtest_main)
add_test(NAME BASIC COMMAND ${PROJECT_NAME}_test)
