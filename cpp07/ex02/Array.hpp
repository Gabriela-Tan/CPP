/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:16:20 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/28 09:15:15 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include <iostream>

template <typename T>

class Array
{
	private:
		T* 				_elements;
		unsigned int	_arraySize;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	unsigned int size() const;

	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Exception! Index is out of bounds.";
			}
	};
};

template <typename T>
Array<T>::Array() : _elements(NULL), _arraySize(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _arraySize(n)
{}

template <typename T>
Array<T>::Array(const Array &other) : _elements(NULL), _arraySize(0)
{
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		T *newElements = new T[other._arraySize]();
		for (unsigned int i = 0; i < other._arraySize; ++i)
			newElements[i] = other._elements[i];

		delete[] this->_elements;
		this->_elements = newElements;
		this->_arraySize = other._arraySize;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _arraySize || !_elements)
		throw OutOfBoundsException();
	return _elements[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _arraySize || !_elements)
		throw OutOfBoundsException();
	return _elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _arraySize;
}

#endif