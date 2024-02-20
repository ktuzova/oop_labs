cmake_minimum_required (VERSION 3.8)

project ("PhobiaTest")

# Добавьте исходный файл в исполняемый файл этого проекта.
add_executable (PhobiaTest "PhobiaTest.cpp" "main.cpp")

# Добавьте исполняемый файл для тестирования
add_executable(CheckTest "test.cpp" "PhobiaTest.cpp")

# Подключите директорию, где находится библиотека Google Test
add_subdirectory(googletest)

# Свяжите библиотеки Google Test с исполняемым файлом для тестирования
target_link_libraries(CheckTest gtest gtest_main)

# Включите поддержку тестирования
enable_testing()

# Добавьте команду тестирования
add_test(NAME CheckTest COMMAND CheckTest)
