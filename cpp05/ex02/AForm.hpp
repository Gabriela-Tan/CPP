/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:27:54 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/26 10:38:22 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const unsigned int _signGrade;
		const unsigned int _execGrade;

	public:
		AForm();
		AForm(const std::string& name, unsigned int signGrade, unsigned int execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		const std::string& getName() const;
		bool isSigned() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;

		void beSigned(const Bureaucrat& bureaucrat);
		
		virtual void	execute(const Bureaucrat& executor) const = 0;

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

		class WasNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& outputStream, const AForm& form);

#endif
