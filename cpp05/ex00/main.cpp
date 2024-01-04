/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:00:48 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/24 10:32:30 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

	std::cout << "Testing demotion and lowest level limit: 149->151" << std::endl;
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

	return 0;
}
