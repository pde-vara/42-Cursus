/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:25:45 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/11 17:03:45 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): brain(new Brain()) //  brain = new Brain();
{
	type = "Dog";
	std::cout << "Dog default constructor called\n" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other), brain(new Brain(*other.brain)) // avant type = other.type;
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);	// Call the base class's copy assignment operator
		delete brain;	// Delete the existing Brain object to avoid memory leaks
		brain = new Brain(*other.brain);// Allocate a new Brain object and copy the contents
	}
	return (*this);
}

Dog::~Dog() 
{
	delete brain;
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "- Waf Waf -" << std::endl;
}
