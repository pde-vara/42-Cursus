/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:22:07 by pde-vara          #+#    #+#             */
/*   Updated: 2025/08/05 17:10:36 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data original;
	original.number = 42;
	original.text = "Hello serialization";

	std::cout << "Original data address: " << &original << std::endl;

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;

	Data* copy = Serializer::deserialize(raw);
	std::cout << "Deserialized data address: " << copy << std::endl;

	if (copy == &original)
		std::cout << "Deserialization successful!" << std::endl;
	else
		std::cout << "Deserialization failed!" << std::endl;

	std::cout << "Data: number = " << copy->number
			  << ", text = " << copy->text << std::endl;

	return 0;
}
