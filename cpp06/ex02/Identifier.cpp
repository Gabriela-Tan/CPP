/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 07:53:12 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/21 10:55:27 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

Base::~Base()
{}

Base* generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return (std::cout << "A" << std::endl, new A);
		case 1:
			return (std::cout << "B" << std::endl, new B);
		case 2:
			return (std::cout << "C" << std::endl, new C);
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A: pointer cast" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B: pointer cast" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C: pointer cast" << std::endl;

}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A: reference cast" << std::endl;
	}
	catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
			std::cout << "B: reference cast" << std::endl;
	}
	catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C: reference cast" << std::endl;
	}
	catch (std::exception&) {}
}
