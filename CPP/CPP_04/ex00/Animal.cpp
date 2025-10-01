/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:24:25 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/09 15:37:26 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

Animal::~Animal() 
{
	std::cout << "Animal destroyed" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "- generic Animal sound... -" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}