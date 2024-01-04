/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:00:48 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/28 11:01:47 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << "\nTesting Presidential Pardon Form:" << std::endl;
	try
	{
		PresidentialPardonForm a("Mr. Pardoned");
		Bureaucrat b("Mr. Highgrade", 5);
		Bureaucrat c("Mr. Lowgrade", 50);
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		// Failed signing by Mr. Lowgrade
		c.signForm(a);
		// Failed executing by Mr. Lowgrade
		c.executeForm(a);
		// Successfull signing by Mr. Highgrade
		b.signForm(a);
		// Successfull execution by Mr. Highgrade
		b.executeForm(a);
	} 
	catch (const std::exception& e)
	{
		std::cerr << "Exception! " << e.what() << std::endl;
	}

	std::cout << "\nTesting Robotomy Request Form:" << std::endl;
	try
	{
		RobotomyRequestForm form1("Mr. First");
		RobotomyRequestForm form2("Mr. Second");
		RobotomyRequestForm form3("Mr. Third");
		RobotomyRequestForm form4("Mr. Fourth");
		RobotomyRequestForm form5("Mr. Fifth");

		Bureaucrat b("Ms. Highgrade", 5);
		std::cout << b << std::endl;
		b.signForm(form1);
		b.signForm(form2);
		b.signForm(form3);
		b.signForm(form4);
		b.signForm(form5);
		form1.execute(b);
		form2.execute(b);
		form3.execute(b);
		form4.execute(b);
		form5.execute(b);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception! " << e.what() << std::endl;
	}

	std::cout << "\nTesting Shrubbery Creation Form:" << std::endl;
	try
	{
		Bureaucrat b("Ms. Shrubbery", 5);
		std::cout << b << std::endl;
		ShrubberyCreationForm shrub1("Home");
		ShrubberyCreationForm shrub2("Campus");

		b.signForm(shrub1);
		b.executeForm(shrub1);
		b.signForm(shrub2);
		b.executeForm(shrub2);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception! " << e.what() << std::endl;
	}

	return 0;
}
