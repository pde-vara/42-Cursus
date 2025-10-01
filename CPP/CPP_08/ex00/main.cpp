
#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	try {
		// --- Test with vector ---
		std::vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);

		std::cout << "Vector test:\n";
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Found: " << *it << std::endl;

		it = easyfind(v, 99); // will throw
		std::cout << "Found: " << *it << std::endl; // won’t execute
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		// --- Test with list ---
		std::list<int> l;
		l.push_back(5);
		l.push_back(15);
		l.push_back(25);

		std::cout << "\nList test:\n";
		std::list<int>::iterator it2 = easyfind(l, 15);
		std::cout << "Found: " << *it2 << std::endl;

		it2 = easyfind(l, 100); // will throw
		std::cout << "Found: " << *it2 << std::endl; // won’t execute
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
