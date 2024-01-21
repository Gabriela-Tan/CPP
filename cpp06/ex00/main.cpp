/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:17:07 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/07 10:57:32 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Wrong input! Run ./convert [value]" << std::endl;
}
