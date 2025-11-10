


#include "PmergeMe.hpp"
#include <iostream>

long getTimeUs() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1000000L + ts.tv_nsec / 1000;
}

int main(int ac, char** av) {
	if (ac < 2) {
		std::cerr << "Usage: ./PmergeMe <list of integer>" << std::endl;
		return 1;
	}

	try {
		PmergeMe sorter;
		sorter.loadInput(ac, av);
		
		//--------vector---------//
		
		sorter.displayVector("Before: ");

		long timeStart = getTimeUs();
		sorter.sortVector();
		long timeProcess = getTimeUs() - timeStart;

		sorter.displayVector("After : ");
		std::cout << "Time to process a range of elements with std::vector: " << timeProcess << " us" <<std::endl;


		//--------deque---------//

		// sorter.displayDeque("Before: ");

		timeStart = getTimeUs();
		sorter.sortDeque();
		timeProcess = getTimeUs() - timeStart;

		// sorter.displayDeque("After : ");
		std::cout << "Time to process a range of elements with std::deque: " << timeProcess << " us" <<std::endl;
		
		sorter.checker();
	}

	catch (const std::exception &e) {
		std:: cerr << e.what() << std::endl;
		return -1;
	}
	return 0;
}