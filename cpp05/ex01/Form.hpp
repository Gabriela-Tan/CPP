/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:27:54 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/25 11:01:47 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const unsigned int _signGrade;
		const unsigned int _execGrade;

	public:
		Form();
		Form(const std::string& name, unsigned int signGrade, unsigned int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getName() const;
		bool isSigned() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;

		void beSigned(const Bureaucrat& bureaucrat);

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

		class WasSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& outputStream, const Form& form);

#endif
