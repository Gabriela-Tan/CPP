/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:43:38 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/03 11:22:02 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed&
Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixedValue = copy.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = intValue * 256;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(floatValue * 256);
}

void
Fixed::setRawBits(int const raw)
{
	_fixedValue = raw;
}

int
Fixed::getRawBits(void) const
{
	return _fixedValue;
}

float
Fixed::toFloat(void) const
{
	return (float)this->_fixedValue / 256;
}

int
Fixed::toInt(void) const
{
	return _fixedValue / 256;
}

//Comparison
bool
Fixed::operator>(Fixed const &other) const
{
	return this->_fixedValue > other._fixedValue;
}

bool
Fixed::operator<(Fixed const &other) const
{
	return this->_fixedValue < other._fixedValue;
}

bool
Fixed::operator>=(Fixed const &other) const
{
	return this->_fixedValue >= other._fixedValue;
}

bool
Fixed::operator<=(Fixed const &other) const
{
	return this->_fixedValue <= other._fixedValue;
}

bool
Fixed::operator==(Fixed const &other) const
{
	return this->_fixedValue == other._fixedValue;
}

bool
Fixed::operator!=(Fixed const &other) const
{
	return this->_fixedValue != other._fixedValue;
}

//Arithmetic
Fixed
Fixed::operator+(Fixed const &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed
Fixed::operator-(Fixed const &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed
Fixed::operator*(Fixed const &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed
Fixed::operator/(Fixed const &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

//Increment/Decrement
Fixed&
Fixed::operator++()
{
	this->_fixedValue++;
	return *this;
}

Fixed
Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed&
Fixed::operator--()
{
	this->_fixedValue--;
	return *this;
}

Fixed
Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(*this);
	return tmp;
}

//Member functions
Fixed&
Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed
const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
}

Fixed&
Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed
const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
}

std::ostream
&operator<<(std::ostream &stream, Fixed const &fixed)
{
	stream << fixed.toFloat();
	return stream;
}
