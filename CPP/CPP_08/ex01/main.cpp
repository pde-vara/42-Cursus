
#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2(10);
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(100);
	vec.push_back(50);
	sp2.addNumbers(vec.begin(), vec.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	try {
		Span small(2);
		small.addNumber(1);
		small.addNumber(2);
		small.addNumber(3); // should throw
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Span bigSpan(10000);
	std::vector<int> bigVector(10000);
	for (int i = 0; i < 10000; ++i) {
		bigVector[i] = i;
	}
	bigSpan.addNumbers(bigVector.begin(), bigVector.end());
	std::cout << bigSpan.shortestSpan() << std::endl;
	std::cout << bigSpan.longestSpan() << std::endl;
		
	return 0;
}