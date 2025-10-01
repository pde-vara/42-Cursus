

#pragma once

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int value);// A constructor that takes a constant integer as a parameter.
		Fixed(const float value);//  constructor that takes a constant floating-point number as a parameter
		Fixed(const Fixed& to_copy); // Copy constructor
		Fixed& operator=(const Fixed& to_copy); // copy assignment operator overload
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
		float toFloat( void ) const; // converts the fixed-point value to a floating-point value
		int toInt( void ) const; // converts the fixed-point value to an integer value.

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();		// Pre-increment
		Fixed operator++(int);		// Post-increment
		Fixed& operator--();		// Pre-decrement
		Fixed operator--(int);		// Post-decrement

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);