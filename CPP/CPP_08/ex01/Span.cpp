


#include "Span.hpp"


Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}


void Span::addNumber(unsigned int n) {
	if (_numbers.size() >= _maxSize)
		throw std::overflow_error("Span is already full");
	_numbers.push_back(n);
}


int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = longestSpan();
	for (size_t i = 0; i < sorted.size() - 1; ++i) {
		minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);
	}
	return minSpan;
}

int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
	return maxVal - minVal;
}
