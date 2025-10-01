

#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>

class Span {

	private :
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public :
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(unsigned int n);

		int shortestSpan();
		int longestSpan();


		template<typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			size_t distance = std::distance(begin, end);
			if (_numbers.size() + distance > _maxSize) {
				throw std::runtime_error("Not enough space in Span for all numbers");
			}
			_numbers.insert(_numbers.end(), begin, end);
		}
};
