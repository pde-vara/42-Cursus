/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:26:19 by pde-vara          #+#    #+#             */
/*   Updated: 2025/07/23 16:36:21 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
	std::cout << "=== Valid Bureaucrat Test ===\n";
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		std::cout << "Incrementing Bob's grade...\n";
		bob.incrementGrade(); // 2 → 1
		std::cout << bob << std::endl;

		std::cout << "Incrementing Bob's grade again (should fail)...\n";
		bob.incrementGrade(); // 1 → exception
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}

	std::cout << "\n=== Invalid Grade on Construction ===\n";
	try {
		Bureaucrat jim("Jim", 151); // Exception: too low
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}

	try {
		Bureaucrat alice("Alice", 0); // Exception: too high
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}

	std::cout << "\n=== Decrement Test ===\n";
	try {
		Bureaucrat joe("Joe", 149);
		std::cout << joe << std::endl;

		std::cout << "Decrementing Joe's grade...\n";
		joe.decrementGrade(); // 149 → 150
		std::cout << joe << std::endl;

		std::cout << "Decrementing Joe's grade again (should fail)...\n";
		joe.decrementGrade(); // 150 → exception
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}

	return 0;
}
