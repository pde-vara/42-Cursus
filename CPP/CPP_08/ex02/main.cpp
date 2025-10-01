
#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "=== Subject Test ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	
	std::cout << "\n=== Custom Tests ===" << std::endl;

	// Reverse iteration
	std::cout << "Reverse iteration:" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << std::endl;
	}

	// Const iteration
	const MutantStack<int> constStack = mstack;
	std::cout << "Const iteration:" << std::endl;
	for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit) {
		std::cout << *cit << std::endl;
	}

	// Compare with std::list
	std::cout << "\nCompare with std::list:" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit) {
		std::cout << *lit << std::endl;
	}

	return 0;
}