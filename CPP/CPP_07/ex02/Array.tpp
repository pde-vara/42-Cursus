

#pragma once


#include <iostream> // optional (for debugging, not required)
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) {
	if (other._size > 0)
	{
		_data = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	else
	{
		_data = NULL;
		_size = 0;
	}
}


template <typename T>
Array<T>::~Array() {
	delete[] _data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::exception();
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::exception();
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}
