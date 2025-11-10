

#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

#include <list>
#include <string>

class RPN {
	private:
		std::list<int> _list;
	
	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();

		int calcul(std::string& line);
};