cmake_minimum_required(VERSION 3.22.1)
project(oop_lab4)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_subdirectory(googletest)
include_directories(include)

add_executable(oop_lab4 main.cpp)
add_executable(oop_lab4_test tests/test.cpp)

target_link_libraries(oop_lab4_test gtest_main)
add_test(NAME BASIC COMMAND oop_lab4_test)