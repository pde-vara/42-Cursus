

#pragma once

#include <stdexcept>
#include <cstddef> 

template <typename T>
class Array {

	private:
		T* _data;            // pointer to dynamically allocated array
		unsigned int _size;  // number of elements

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		// Element access
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;


		unsigned int size() const;
};
