/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:29:43 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/03 10:46:53 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <string>
#include <algorithm> // For std::sort
#include <limits>    // For std::numeric_limits

class Span
{
	private:
		unsigned int _capacity;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int capacity);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan() const;
		int longestSpan() const;

		class FullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("The span is already full!");
				}
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Not enough elements to create a span!");
				}
		};
};

#endif
