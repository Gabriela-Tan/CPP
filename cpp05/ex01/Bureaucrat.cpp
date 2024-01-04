/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:00:59 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/25 11:16:36 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(MIN)
{}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade)
{
	if (grade < MAX)
		throw GradeTooHighException();
	if (grade > MIN)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

const std::string&
Bureaucrat::getName() const
{
	return _name;
}

unsigned int
Bureaucrat::getGrade() const
{
	return _grade;
}

void
Bureaucrat::incrementGrade()
{
	if (_grade <= MAX)
		throw GradeTooHighException();
	--_grade;
}

void
Bureaucrat::decrementGrade()
{
	if (_grade >= MIN)
		throw GradeTooLowException();
	++_grade;
}

const char*
Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char*
Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

void
Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&
operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat)
{
	outputStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return outputStream;
}
