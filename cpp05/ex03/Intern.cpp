/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:52:42 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/28 10:10:37 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return *this;
}

Intern::~Intern()
{}

AForm*
Intern::makeForm(const std::string& formName, const std::string& target) const
{
	AForm* (*ptrArray[])(const std::string&) = {&Intern::makescf, &Intern::makerrf, &Intern::makeppf};
	const char* formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ptrArray[i](target);
		}
	}
	throw Intern::UnknownException();
}

AForm*
Intern::makescf(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm*
Intern::makerrf(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm*
Intern::makeppf(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

const char*
Intern::UnknownException:: what(void) const throw()
{
	return ("Intern has never heard of this form.");
}