/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:01:16 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/03 11:48:30 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) // default constructor that initializes the fixed-point number value to 0.
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) // A constructor that takes a constant integer as a parameter.
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits; // like = value * 256
}

Fixed::Fixed(const float value) //  constructor that takes a constant floating-point number as a parameter
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits)); // inverse de toFloat
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

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const {
	return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat(); // Convert fixed-point to float for display
    return out;
}
