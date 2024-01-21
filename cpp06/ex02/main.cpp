/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 07:53:21 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/21 10:55:13 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

int main(void)
{
	 srand(time(0));

// Generate classes:
	std::cout << "1. class was generated:" << std::endl;
	Base *p1 = generate();
	std::cout << "2. class was generated:" << std::endl;
	Base *p2 = generate();
	std::cout << "3. class was generated:" << std::endl;
	Base *p3 = generate();
	std::cout << "4. class was generated:" << std::endl;
	Base *p4 = generate();
	std::cout << "5. class was generated:" << std::endl;
	Base *p5 = generate();

// Testing classes:
	identify(p1);
	identify(*p1);
	identify(p2);
	identify(*p2);
	identify(p3);
	identify(*p3);
	identify(p4);
	identify(*p4);
	identify(p5);
	identify(*p5);

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
}
