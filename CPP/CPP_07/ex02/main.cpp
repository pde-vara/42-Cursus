/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:19:29 by pde-vara          #+#    #+#             */
/*   Updated: 2025/09/05 15:03:15 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include "Array.tpp"


int main() {
	try {
		// --- Int array ---
		Array<int> a(5); // 5 ints initialized to 0
		std::cout << "size of a: " << a.size() << std::endl;

		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i * 10;

		std::cout << "a: ";
		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		// --- Copy constructor ---
		Array<int> b = a;
		b[0] = 999;
		std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << std::endl;

		// --- Assignment operator ---
		Array<int> c;
		c = a;
		c[1] = 888;
		std::cout << "a[1] = " << a[1] << ", c[1] = " << c[1] << std::endl;

		// --- String array ---
		Array<std::string> s(3);
		s[0] = "Hello";
		s[1] = "C++";
		s[2] = "World";
		for (unsigned int i = 0; i < s.size(); i++)
			std::cout << s[i] << " ";
		std::cout << std::endl;

		// --- Out of bounds ---
		std::cout << a[10] << std::endl; // should throw
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
