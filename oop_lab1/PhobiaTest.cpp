﻿// PhobiaTest.cpp: определяет точку входа для приложения.
//

#include "PhobiaTest.hpp"

#include <iostream>
#include <string>

bool checkPhobia(const std::string& day, int number) {
	if ((day == "Понедельник" && number == 12) ||
		(day == "Вторник" && number > 95) ||
		(day == "Среда" && number == 34) ||
		(day == "Четверг" && number == 0) ||
		(day == "Пятница" && number % 2 == 0) ||
		(day == "Суббота" && number == 56) ||
		(day == "Воскресенье" && (number == 666 || number == -666))) {
		return true;
	}
	else {
		return false;
	}
}
