/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:27:45 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/25 11:23:41 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _signGrade(MIN), _execGrade(MIN)
{}

AForm::AForm(const std::string& name, unsigned int signGrade, unsigned int execGrade) 
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < MAX || execGrade < MAX)
		throw GradeTooHighException();
	if (signGrade > MIN || execGrade > MIN)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{}

const std::string&
AForm::getName() const
{
	return _name;
}

bool
AForm::isSigned() const
{
	return _isSigned;
}

unsigned int
AForm::getSignGrade() const
{
	return _signGrade;
}

unsigned int
AForm::getExecGrade() const
{
	return _execGrade;
}

void
AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (_isSigned)
		throw WasSignedException();
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void
AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw WasNotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}

const char*
AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high.";
}

const char*
AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low.";
}

const char*
AForm::WasSignedException::what() const throw()
{
	return "it was already signed.";
}

const char*
AForm::WasNotSignedException::what() const throw()
{
	return "it was not signed. Come again tomorrow.";
}

std::ostream&
operator<<(std::ostream& outputStream, const AForm& form)
{
	outputStream << "Form: " << form.getName() <<
		", Sign Grade: " << form.getSignGrade() <<
		", Execute Grade: " << form.getExecGrade() <<
		", Is Signed: " << (form.isSigned() ? "Yes" : "No") << std::endl;
	return outputStream;
}
