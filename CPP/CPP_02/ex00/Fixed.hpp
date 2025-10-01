

#pragma once

#include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue; // store the fixed-point number value.
		static const int	_fractionalBits = 8; // to store the number of fractional bits = 8

	public:
		Fixed();  // Default constructor
		Fixed(const Fixed& to_copy);  // Copy constructor
		Fixed& operator=(const Fixed& to_copy); // copy assignment operator overload
		~Fixed();  // Destructor

		int getRawBits( void ) const; // returns the raw value of the fixed-point value
		void setRawBits( int const raw ); // sets the raw value of the fixed-point number.
};