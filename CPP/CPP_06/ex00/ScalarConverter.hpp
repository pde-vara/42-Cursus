


#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <limits>
#include <cfloat>
#include <cmath>

class ScalarConverter
{
	public:
		static void convert(const std::string& literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

};
