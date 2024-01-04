/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:00:48 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/04 09:43:47 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm *rrf;
	AForm *scf;
	AForm *ppf;

	std::cout << "Testing all kinds of forms:" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	scf = someRandomIntern.makeForm("shrubbery creation", "Campus");
	if (scf) {
		std::cout << *scf << std::endl;
		delete scf;
	}

	ppf = someRandomIntern.makeForm("presidential pardon", "Mr. Pardoned");
	if (ppf) {
		std::cout << *ppf << std::endl;
		delete ppf;
	}

	try
	{
		ppf = someRandomIntern.makeForm("unknown form", "Unknown");
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception! " << e.what() << std::endl;
	}
	
	return 0;
}
