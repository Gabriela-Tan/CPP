/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:00:48 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/25 12:14:25 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "Testing promotion and highest level limit: 2->0" << std::endl;
	try
	{
		Bureaucrat a("Mr. Bureaucrat", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception! " << e.what() << std::endl;
	}

	std::cout << "\nTesting demotion and lowest level limit: 149->151" << std::endl;
	try
	{
		Bureaucrat b("Mr. Willbefired", 149);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception! " << e.what() << std::endl;
	}

	std::cout << "\nSigning form with insufficient grade:" << std::endl;
	try
	{
		Form formA("Form A", 3, 5);
		Bureaucrat c("Mr. Lowgrade", 4);
		std::cout << c << std::endl;
		std::cout << formA << std::endl;
		c.signForm(formA);
		c.incrementGrade();
		std::cout << c << std::endl;
		c.signForm(formA);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception! " << e.what() << std::endl;
	}

	std::cout << "\nSigning same form twice:" << std::endl;
	try
	{
		Form formB("Form B", 10, 20);
		Bureaucrat d("Mr. Twice", 9);
		std::cout << d << std::endl;
		std::cout << formB << std::endl;
		d.signForm(formB);
		d.signForm(formB);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception! " << e.what() << std::endl;
	}

	return 0;
}
