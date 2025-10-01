/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:39:45 by pde-vara          #+#    #+#             */
/*   Updated: 2025/09/02 11:24:48 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

ScalarConverter::~ScalarConverter() {}





void ScalarConverter::convert(const std::string& literal)
{
	double value = 0;

	// Step 1: Handle special float/double cases
	if (literal == "nan" || literal == "nanf")
		value = std::numeric_limits<double>::quiet_NaN(); // not signaling_NaN
	else if (literal == "+inf" || literal == "+inff")
		value = std::numeric_limits<double>::infinity();
	else if (literal == "-inf" || literal == "-inff")
		value = -std::numeric_limits<double>::infinity();

	// Step 2: Handle char (e.g. 'a')
	else if (literal.length() == 1 && !isdigit(literal[0])) {
		char c = literal[0];
		value = static_cast<double>(c);
	}

	// Step 3: Handle numeric input
	else {
		char* endptr; // points the first invalid character in the str
		value = std::strtod(literal.c_str(), &endptr); //strtod converts C-string into double.
		if (*endptr != '\0' && *endptr != 'f')
		{
			std::cerr << "Invalid input." << std::endl;
			return;
		}
	}

	// Print char
	std::cout << "char: ";
	if (value < 0 || value > 127 || isnan(value)) // = is ascii
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<char>(value))) // = is printable
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

	// Print int
	std::cout << "int: ";
	if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX) || isnan(value))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	// Print float
	std::cout << "float: " << static_cast<float>(value);
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	// Print double
	std::cout << "double: " << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}
