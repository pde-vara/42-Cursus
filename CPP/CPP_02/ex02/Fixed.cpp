/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:01:16 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/06 12:15:02 by pde-vara         ###   ########.fr       */
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
	_fixedPointValue = to_copy._fixedPointValue; // or *this = to_copy;
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



bool Fixed::operator>(const Fixed& other) const {
	return (_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed& other) const {
	return (_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed& other) const {
	return (_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (_fixedPointValue != other._fixedPointValue);
}


Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result._fixedPointValue = _fixedPointValue - other._fixedPointValue; // this-> pas necessaire
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result._fixedPointValue = (_fixedPointValue * other._fixedPointValue) >> _fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result._fixedPointValue = (_fixedPointValue << _fractionalBits) / other._fixedPointValue;
	return result;
}



Fixed& Fixed::operator++()		// Pre-increment
{
	_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int)		// Post-increment
{
	Fixed temp = *this;
	++(*this); // == _fixedPointValue++;
	return temp;
}

Fixed& Fixed::operator--()		// Pre-decrement
{
	_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int)		// Post-decrement
{
	Fixed temp = *this;
	--(*this); // == _fixedPointValue--;
	return temp;
}



Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b; // pareil
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b; // pareil
}


std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat(); // Convert fixed-point to float for display
    return out;
}
