/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:25:11 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/11 17:03:53 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat default constructor called\n" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other), brain(new Brain(*other.brain)) // avant type = other.type;
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);	// Call the base class's copy assignment operator
		delete brain;	// Delete the existing Brain object to avoid memory leaks
		brain = new Brain(*other.brain);// Allocate a new Brain object and copy the contents
	}
	return (*this);
}

Cat::~Cat() 
{
	delete brain;
	std::cout << "Cat destroyed" << std::endl;
}


void Cat::makeSound() const
{
	std::cout << "- Meow Meow -" << std::endl;
}

