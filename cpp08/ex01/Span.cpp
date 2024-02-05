/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:29:41 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/04 10:00:47 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{}

Span::Span(unsigned int capacity) : _capacity(capacity)
{}

Span::Span(const Span& other) : _capacity(other._capacity), _numbers(other._numbers)
{}

Span&
Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_capacity = other._capacity;
		_numbers = other._numbers;
	}	
	return *this;

}

Span::~Span()
{}

void
Span::addNumber(int number)
{
	if (_numbers.size() >= _capacity)
		throw FullSpanException();

	_numbers.push_back(number);
}

void
Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}

int
Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int> sortedNumbers(_numbers);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = std::numeric_limits<int>::max();
	for (int i = 1; i < sortedNumbers.size(); ++i)
	{
		int currentSpan = sortedNumbers[i] - sortedNumbers[i-1];
		if (currentSpan < minSpan)
			minSpan = currentSpan;
    }
	return minSpan;
}

int
Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	int minNumber = *std::min_element(_numbers.begin(), _numbers.end());
	int maxNumber = *std::max_element(_numbers.begin(), _numbers.end());

	return maxNumber - minNumber;
}
