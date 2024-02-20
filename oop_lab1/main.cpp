#include "PhobiaTest.hpp"
#include <iostream>
#include <string>
int main() {
	int num;
	std::string day; // Use std::string for string input
	std::cout << "Введите день недели (с большой буквы, пожалуйста): ";
	std::cin >> day;
	std::cout << "Введите число: ";
	std::cin >> num;
	std::cout << std::boolalpha << checkPhobia(day, num); // Printing boolean value
	return 0;
}