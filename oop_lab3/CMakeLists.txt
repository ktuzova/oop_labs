cmake_minimum_required(VERSION 3.22.1)
project(oop_lab3)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_subdirectory(googletest)
include_directories(include)

add_executable(oop_lab3 main.cpp src/Point.cpp  src/Hexagon.cpp src/Octagon.cpp src/FigureList.cpp
        src/Pentagon.cpp)
add_executable(oop_lab3_test tests/test.cpp src/Point.cpp src/Hexagon.cpp src/Octagon.cpp src/FigureList.cpp src/Pentagon.cpp)

target_link_libraries(oop_lab3_test gtest_main)
add_test(NAME BASIC COMMAND oop_lab3_test)
