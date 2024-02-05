/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:29:39 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/03 11:13:40 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	// Add more numbers than capacity
	try
	{
		sp.addNumber(13);
    }
	catch (const Span::FullSpanException& e)
	{
		std::cout << "Exception! " << e.what() << std::endl;
	}

	// create span without enough numbers
	try
	{
		Span empty(10);
		empty.addNumber(1);
		std::cout << empty.shortestSpan() << std::endl;
	}
	catch (const Span::NoSpanException& e)
	{
		std::cout << "Exception! " << e.what() << std::endl;
	}

	// Test with min. 10k numbers
	Span large(10000);
	std::vector<int> numbers;
	for (int i = 0; i < 10000; ++i)
		numbers.push_back(i);
    large.addRange(numbers.begin(), numbers.end());

    std::cout << "Shortest span: " << large.shortestSpan() << std::endl;
    std::cout << "Longest span: " << large.longestSpan() << std::endl;

    return 0;
}
