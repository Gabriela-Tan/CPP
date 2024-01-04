/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:27:45 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/28 11:02:57 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false), _signGrade(MIN), _execGrade(MIN)
{}

Form::Form(const std::string& name, unsigned int signGrade, unsigned int execGrade) 
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < MAX || execGrade < MAX)
		throw GradeTooHighException();
	if (signGrade > MIN || execGrade > MIN)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{}

const std::string&
Form::getName() const
{
	return _name;
}

bool
Form::isSigned() const
{
	return _isSigned;
}

unsigned int
Form::getSignGrade() const
{
	return _signGrade;
}

unsigned int
Form::getExecGrade() const
{
	return _execGrade;
}

void
Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
		throw WasSignedException();
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char*
Form::GradeTooHighException::what() const throw()
{
	return "grade is too high.";
}

const char*
Form::GradeTooLowException::what() const throw()
{
	return "grade is too low.";
}

const char*
Form::WasSignedException::what() const throw()
{
	return "it was already signed.";
}

std::ostream&
operator<<(std::ostream& outputStream, const Form& form)
{
	outputStream << "Form: " << form.getName() <<
		", Sign Grade: " << form.getSignGrade() <<
		", Execute Grade: " << form.getExecGrade() <<
		", Is Signed: " << (form.isSigned() ? "Yes" : "No") << std::endl;
	return outputStream;
}
