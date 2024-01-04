/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:52:34 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/28 10:08:58 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern 
{
	private:
		static AForm* makescf(const std::string& target);
		static AForm* makerrf(const std::string& target);
		static AForm* makeppf(const std::string& target);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target) const;

		class UnknownException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif
