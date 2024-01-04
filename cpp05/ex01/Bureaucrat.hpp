/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:00:53 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/25 09:40:53 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

#define MIN 150
#define MAX 1

#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
		unsigned int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(Form &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat);

#endif
