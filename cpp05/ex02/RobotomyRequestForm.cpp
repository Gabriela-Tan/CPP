/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:27:09 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/04 09:40:58 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void) other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void
RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);
	std::cout << "*bzzzzzzz bzzzz bzzzzz*" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy of " << _target << " failed. Come again tomorrow." << std::endl;
}
