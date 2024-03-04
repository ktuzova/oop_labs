cmake_minimum_required(VERSION 3.22.1)
project(oop_lab2)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_subdirectory(googletest)
include_directories(include)

add_executable(oop_lab2 main.cpp src/Seven.cpp)
add_executable(oop_lab2_test tests/test.cpp src/Seven.cpp)

target_link_libraries(oop_lab2_test gtest_main)
add_test(NAME BASIC COMMAND oop_lab2_test)
