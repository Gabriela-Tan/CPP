/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:15:08 by gabriela          #+#    #+#             */
/*   Updated: 2023/11/25 11:56:53 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string* stringPTR = &stringVAR;
	std::string& stringREF = stringVAR;

	std::cout << "Memory address of string variable: " << &stringVAR << std::endl;
	std::cout << "Memory address held by stringPTR. " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF. " << &stringREF << std::endl;
	std::cout << "Value of the string variable. " << stringVAR << std::endl;
	std::cout << "Value pointed to by stringPTR. " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF. " << stringREF << std::endl;

	return 0;
}