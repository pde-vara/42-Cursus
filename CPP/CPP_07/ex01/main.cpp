/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:19:29 by pde-vara          #+#    #+#             */
/*   Updated: 2025/09/04 16:17:36 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// Function to print any type (read-only)
template <typename T>
void print(const T& x) {
	std::cout << x << " ";
}

// Function to increment numbers (in place)
template <typename T>
void addOne(T& x) {
	++x;
}

// Function to uppercase chars (in place)
void uppercaseChar(char& c) {
	c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

int main() {
	// --- Non-const array: mutation test ---
	int nums[] = {1, 2, 3};
	std::cout << "nums before: ";
	iter(nums, 3, print<int>);
	std::cout << "\n";

	iter(nums, 3, addOne<int>);  // proves non-const support

	std::cout << "nums after addOne: ";
	iter(nums, 3, print<int>);
	std::cout << "\n\n";

	// --- Const array: read-only test ---
	const std::string words[] = {"hello", "world"};
	std::cout << "words (const): ";
	iter(words, 2, print<std::string>);  // proves const support
	std::cout << "\n";

	return 0;
}
