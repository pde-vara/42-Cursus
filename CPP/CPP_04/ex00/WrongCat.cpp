/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:25:11 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/09 15:12:37 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	type = other.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

WrongCat::~WrongCat() 
{
	std::cout << "WrongCat destroyed" << std::endl;
}


void WrongCat::makeSound() const
{
	std::cout << "- weoM weoM -" << std::endl;
}

