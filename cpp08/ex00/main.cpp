/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:25:58 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/02 11:12:19 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> numbers(array, array + sizeof(array) / sizeof(int));

	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 8);
		std::cout << "Found number: " << *it << std::endl;
	}
	catch (const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 42);
		std::cout << "Found numbers: " << *it << std::endl;
	}
	catch (const NotFoundException& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
