

#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

#include <deque>
#include <vector>
#include <string>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
	
		std::vector<int> _jacob;


	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		void loadInput(int ac, char** av);
		void displayVector(std::string str);
		void displayDeque(std::string str);

		
		void checker();
		void jacobsthal(size_t limit);

		struct PairGroup {
			int smaller;
			int larger;
		};
		
		
		void sortVector();
		void makePairs(std::vector<int> &arr);
		std::vector<int> buildMainChain(const std::vector<int> &arr, std::vector<PairGroup> &pairs);
		void binaryInsert(std::vector<int> &mainChain, int value, size_t maxPos);
		void insertPend(std::vector<PairGroup> &pairs, std::vector<int> &vecChain);


		void sortDeque();
		void makePairs(std::deque<int> &arr);
		std::deque<int> buildMainChain(const std::deque<int> &arr, std::deque<PairGroup> &pairs);
		void binaryInsert(std::deque<int> &mainChain, int value, size_t maxPos);
		void insertPend(std::deque<PairGroup> &pairs, std::deque<int> &vecChain);
};
