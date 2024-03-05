cmake_minimum_required(VERSION 3.10)
project(oop_lab7)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${INCLUDE_DIR}/*.hpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

enable_testing()
add_executable(${PROJECT_NAME}_test test/test.cpp ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME}_test gtest_main)
add_test(NAME BASIC COMMAND ${PROJECT_NAME}_test)
