

#include "PmergeMe.hpp"
#include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}


void PmergeMe::loadInput(int ac, char** av) {
	for (int i = 1; i < ac; ++i)
	{
		char *endptr;
		double num = std::strtod(av[i], &endptr);

		if (num < 0 || num > INT_MAX || *endptr != '\0')
			throw std::runtime_error("Error: loading");
		
		_vector.push_back(num);
		_deque.push_back(num);
	}
}

void PmergeMe::displayVector(std::string str)
{
	std::cout << str;
	
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::displayDeque(std::string str)
{
	std::cout << str;
	
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
 
void PmergeMe::checker() {
	for (size_t i = 1; i < _vector.size(); ++i)
	{
		if (_vector[i] < _vector[i - 1])
			throw std::runtime_error("Error: Vector is not sorted");
		if (_vector[i] == _vector[i - 1])
			throw std::runtime_error("Error: Dooples");
	}

	for (size_t i = 1; i < _deque.size(); ++i)
	{
		if (_deque[i] < _deque[i - 1])
			throw std::runtime_error("Error: Deque is not sorted");
		if (_deque[i] == _deque[i - 1])
			throw std::runtime_error("Error: Dooples");
	}
}

void PmergeMe::jacobsthal(size_t limit)
{
	_jacob.clear();
	_jacob.push_back(0);
	_jacob.push_back(1);
		
	size_t n = 2;
	while (true) {
		size_t next = _jacob[n - 1] + 2 * _jacob[n - 2];
		if (next >= limit)
			break;
		_jacob.push_back(next);
		n++;
		// std::cout << "Jacob: " << next;
	}
	// std::cout << std::endl;

}

/***********
 * 	Vector *
 **************************************************************************************************************************/

void PmergeMe::binaryInsert(std::vector<int> &mainChain, int value, size_t maxPos) {
	std::vector<int>::iterator searchEnd = mainChain.begin() + maxPos;
	std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), searchEnd, value);
	mainChain.insert(pos, value);
}

std::vector<int> PmergeMe::buildMainChain(const std::vector<int> &arr, std::vector<PairGroup> &pairs)
{
	pairs.clear();
		
	for (size_t i = 0; i < arr.size() - 1; i += 2) {
		int a = arr[i];
		int b = arr[i+1];
		if (a > b)
			std::swap(a, b);
		
		pairs.push_back((PairGroup){a, b}); // smaller, larger
	}
		
	std::vector<int> mainChain;	// Extract just the larger values for the main chain
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].larger);
		
	return mainChain;
}

void PmergeMe::insertPend(std::vector<PairGroup> &pairs, std::vector<int> &vecChain)
{
	if (pairs.size() <= 1)
		return;

	jacobsthal(pairs.size());

	std::vector<bool> inserted(pairs.size(), false);// Tracker
	inserted[0] = true;

	for (size_t i = 2; i < _jacob.size(); i++)
	{
		size_t jacobIndex = _jacob[i];
		size_t prevJacobIndex = _jacob[i - 1];

		if (jacobIndex >= pairs.size())
			jacobIndex = pairs.size() - 1;
			
		// Insert in reverse order from jacobIndex down to prevJacobIndex + 1
		for (size_t j = (jacobIndex); j > (prevJacobIndex); j--) {
			size_t idx = j;
			if (idx < pairs.size() && !inserted[idx]) {
				std::vector<int>::iterator mainPos = std::find(vecChain.begin(), vecChain.end(), pairs[idx].larger);
				if (mainPos != vecChain.end()) {
					size_t maxSearchPos = std::distance(vecChain.begin(), mainPos) + 1;
					binaryInsert(vecChain, pairs[idx].smaller, maxSearchPos);
					inserted[idx] = true;
				}
			}
		}
	}
	// Insert any remaining pend elements
	for (size_t i = 1; i < pairs.size(); i++) {
		if (!inserted[i]) {
			std::vector<int>::iterator mainPos = std::find(vecChain.begin(), vecChain.end(), pairs[i].larger);
			if (mainPos != vecChain.end()) {
				size_t maxSearchPos = std::distance(vecChain.begin(), mainPos) + 1;
				binaryInsert(vecChain, pairs[i].smaller, maxSearchPos);
		   	}
		}
	}
}

void PmergeMe::makePairs(std::vector<int> &vecChain)
{
	if (vecChain.size() <= 1)
		return;

	std::vector<PairGroup> pairs;
	std::vector<int> mainChain = buildMainChain(vecChain, pairs);

	int leftover = -1;
	if (vecChain.size() % 2 != 0)
		leftover = vecChain.back();

	if (mainChain.size() > 1) 	// Recursively sort the main chain (with pairs attached)
	{
		makePairs(mainChain);

		std::vector<PairGroup> sortedPairs;		// After sorting mainChain, reorder pairs
		for (size_t i = 0; i < mainChain.size(); i++)
		{
			for (size_t j = 0; j < pairs.size(); j++)
			{
				if (pairs[j].larger == mainChain[i])
				{
					sortedPairs.push_back(pairs[j]);
					break;
				}
			}
		}
		pairs = sortedPairs;
	}

	vecChain = mainChain;

	if (!pairs.empty()) {
		vecChain.insert(vecChain.begin(), pairs[0].smaller); // Insert first pend element
	}

	insertPend(pairs, vecChain);

	if (leftover != -1)
		binaryInsert(vecChain, leftover, vecChain.size());
}

void PmergeMe::sortVector() {
	if (_vector.size() <= 1)
		return;
	makePairs(_vector);
}



/***********
 * 	Deque  *
 ****************************************************************************************************************************/


void PmergeMe::binaryInsert(std::deque<int> &mainChain, int value, size_t maxPos) {
	std::deque<int>::iterator searchEnd = mainChain.begin() + maxPos;
	std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), searchEnd, value);
	mainChain.insert(pos, value);
}

std::deque<int> PmergeMe::buildMainChain(const std::deque<int> &arr, std::deque<PairGroup> &pairs)
{
	pairs.clear();
		
	for (size_t i = 0; i < arr.size() - 1; i += 2) {
		int a = arr[i];
		int b = arr[i+1];
		if (a > b)
			std::swap(a, b);
		
		pairs.push_back((PairGroup){a, b}); // smaller, larger
	}
		
	std::deque<int> mainChain;	// Extract just the larger values for the main chain
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].larger);
		
	return mainChain;
}

void PmergeMe::insertPend(std::deque<PairGroup> &pairs, std::deque<int> &vecChain)
{
	if (pairs.size() <= 1)
		return;

	jacobsthal(pairs.size());

	std::deque<bool> inserted(pairs.size(), false);// Tracker
	inserted[0] = true;

	for (size_t i = 2; i < _jacob.size(); i++)
	{
		size_t jacobIndex = _jacob[i];
		size_t prevJacobIndex = _jacob[i - 1];

		if (jacobIndex >= pairs.size())
			jacobIndex = pairs.size() - 1;
			
		// Insert in reverse order from jacobIndex down to prevJacobIndex + 1
		for (size_t j = (jacobIndex); j > (prevJacobIndex); j--) {
			size_t idx = j;
			if (idx < pairs.size() && !inserted[idx]) {
				std::deque<int>::iterator mainPos = std::find(vecChain.begin(), vecChain.end(), pairs[idx].larger);
				if (mainPos != vecChain.end()) {
					size_t maxSearchPos = std::distance(vecChain.begin(), mainPos) + 1;
					binaryInsert(vecChain, pairs[idx].smaller, maxSearchPos);
					inserted[idx] = true;
				}
			}
		}
	}
	// Insert any remaining pend elements
	for (size_t i = 1; i < pairs.size(); i++) {
		if (!inserted[i]) {
			std::deque<int>::iterator mainPos = std::find(vecChain.begin(), vecChain.end(), pairs[i].larger);
			if (mainPos != vecChain.end()) {
				size_t maxSearchPos = std::distance(vecChain.begin(), mainPos) + 1;
				binaryInsert(vecChain, pairs[i].smaller, maxSearchPos);
		   	}
		}
	}
}

void PmergeMe::makePairs(std::deque<int> &vecChain)
{
	if (vecChain.size() <= 1)
		return;

	std::deque<PairGroup> pairs;
	std::deque<int> mainChain = buildMainChain(vecChain, pairs);

	int leftover = -1;
	if (vecChain.size() % 2 != 0)
		leftover = vecChain.back();

	if (mainChain.size() > 1) 	// Recursively sort the main chain (with pairs attached)
	{
		makePairs(mainChain);

		std::deque<PairGroup> sortedPairs;		// After sorting mainChain, reorder pairs
		for (size_t i = 0; i < mainChain.size(); i++)
		{
			for (size_t j = 0; j < pairs.size(); j++)
			{
				if (pairs[j].larger == mainChain[i])
				{
					sortedPairs.push_back(pairs[j]);
					break;
				}
			}
		}
		pairs = sortedPairs;
	}

	vecChain = mainChain;

	if (!pairs.empty()) {
		vecChain.insert(vecChain.begin(), pairs[0].smaller); // Insert first pend element
	}

	insertPend(pairs, vecChain);

	if (leftover != -1)
		binaryInsert(vecChain, leftover, vecChain.size());
}

void PmergeMe::sortDeque() {
	if (_deque.size() <= 1)
		return;
	makePairs(_deque);
}