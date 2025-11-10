


#include "RPN.hpp"
#include <iostream>


int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return 1;
    }

	std::string line(av[1]);

	RPN calculator;

	try {
		int result = calculator.calcul(line);
		if (result < 0)
			throw std::runtime_error("Error: overflow");
		std::cout << result << std::endl;

	}
	catch (const std::exception &e) {
		std:: cerr << e.what() << std::endl;
		return -1;
	}
	return 0;
}