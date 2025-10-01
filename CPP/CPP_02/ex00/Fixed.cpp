/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:01:16 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/02 18:05:54 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) // default constructor that initializes the fixed-point number value to 0.
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& to_copy) // copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = to_copy._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& to_copy) // copy assignment operator overload
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_copy)
		_fixedPointValue = to_copy._fixedPointValue;
	return *this;
}

Fixed::~Fixed() // destructor
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const // returns the raw value of the fixed-point value
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits( int const raw ) // sets the raw value of the fixed-point number.
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}
