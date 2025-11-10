
#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdexcept>
#include <limits>



std::string trim(std::string& str) {
	str.erase(0, str.find_first_not_of(" \t"));
	str.erase(str.find_last_not_of(" \t") + 1);
	return (str);
}


int stringToInt(const std::string& str) {
	std::istringstream ss(str);
	int value;
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		throw std::runtime_error("Invalid integer");
	}
	return value;
}


bool isValidDate(const std::string& date) {
	std::istringstream sts(date);
	std::string yearStr, monthStr, dayStr;
	
	if (!std::getline(sts, yearStr, '-') || !std::getline(sts, monthStr, '-') || !std::getline(sts, dayStr)) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (yearStr.size() != 4 || monthStr.size() != 2 || dayStr.size() != 2) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	int year, month, day;
	try {
		year = stringToInt(yearStr);
		month = stringToInt(monthStr);
		day = stringToInt(dayStr);
	}
	catch (const std::exception &e) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (month < 1 || month > 12) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	int dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		dayInMonth[1] = 29;

	if (day > dayInMonth[month - 1])
		return false;
	
	return true;
}

float stringToFloat(const std::string& str) {
	std::istringstream ss(str);
	float value;
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		throw std::runtime_error("Invalid float");
	}
	return value;
}

bool isValidValue(std::string valueStr, float &value){
	try {
		value = stringToFloat(valueStr);
	} catch (const std::runtime_error &e) {
		std::cout << "Error: not a number => " << valueStr << std::endl;
		return false;
	}

	if (value < 0.0f){
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000.0f){
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

int main(int ac, char** av) {
	if (ac != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return -1;
	}

	try {
		BitcoinExchange btc("data.csv");
		std::ifstream input(av[1]);
		if (!input)
			throw std::runtime_error("Cannot open input");
		
		std::string line;
		while (std::getline(input, line))
		{
			std::stringstream sts(line);
			std::string date, valueStr;
			if (!std::getline(sts, date, '|') || !std::getline(sts, valueStr)) {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}
			date = trim(date);
			valueStr = trim(valueStr);
			float value;
			if (isValidDate(date) && isValidValue(valueStr, value))
			{
				float rate = btc.getRate(date);
				std::cout << date << " => " << value << " = " << value * rate << std::endl;
			}
		}


	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
