/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:03:12 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/24 09:44:50 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& other)
{
	_numbers = other._numbers;
}

RPN&
RPN::operator=(const RPN& other)
{
	if (this != &other)
		_numbers = other._numbers;
	return *this;
}

RPN::~RPN()
{}

bool
RPN::isOperator(const char& token) const
{
	return token == '+' || token == '-' || token == '*' || token == '/';
}

void
RPN::calculate(const char& operation)
{
	int result = 0;
	int right = _numbers.top();
	_numbers.pop();
	int left = _numbers.top();
	_numbers.pop();

	switch (operation)
	{
		case '+':
			result = left + right;
			break;
		case '-':
			result = left - right;
			break;
		case '*':
			result = left * right;
			break;
		case '/': 
			if (right == 0)
				return;
			result = left / right; 
			break;
	}
	_numbers.push(result);
}

void
RPN::parse(const std::string& expression)
{
	std::istringstream stream(expression);
	std::string token;

	while (stream >> token)
	{
		if (token.length() == 1 && isOperator(token[0]))
		{
			if (_numbers.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			calculate(token[0]);
		}
		else
		{
			std::istringstream tokenStream(token);
			int number;
			if (tokenStream >> number)
				_numbers.push(number);
			else
			{
				std::cerr << "Error" << std::endl;
				return;
			}
		}
	}
	if (_numbers.size() != 1)
		std::cerr << "Error" << std::endl;
	else
		std::cout << _numbers.top() << std::endl;
}

bool
isValid(const char* str)
{
	if (*str == '\0')
		return false;

	for (; *str != '\0'; ++str)
	{
		if (!(*str >= '0' && *str <= '9') && *str != '+' && *str != '-' && *str != '*' && *str != '/' && *str != ' ')
			return false;
	}
	return true;
}
