

#include "RPN.hpp"
#include <climits>

RPN::RPN() {}

RPN::RPN(const RPN &other) : _list(other._list) {}

RPN& RPN::operator=(const RPN &other) {
	if (this != &other)
		_list = other._list;
	return *this;
}

int RPN::calcul(std::string& line)
{
	std::istringstream sts(line);
	std::string token;

	while (sts >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_list.size() < 2)
				throw std::runtime_error("Error: too few numbers");

			int b = _list.back(); _list.pop_back();
			int a = _list.back(); _list.pop_back();
		
			if (token == "+") _list.push_back(a + b);
			if (token == "-") _list.push_back(a - b);
			if (token == "*") _list.push_back(a * b);
			if (token == "/") {
				if (b == 0)
					throw std::runtime_error("Error: Division by zero");
				_list.push_back(a / b);
			}
		}
		else
		{
			char* endptr;
			double nombre = std::strtol(token.c_str(), &endptr, 10);
			if (nombre > 9)
					throw std::runtime_error("Error: numbers must be singleton");
			if (*endptr != '\0')
					throw std::runtime_error("Error");
			_list.push_back(nombre);
		}
	}
	if (_list.size() != 1)
		throw std::runtime_error("Error: nb of arg");
	return _list.back();
}



RPN::~RPN() {}
