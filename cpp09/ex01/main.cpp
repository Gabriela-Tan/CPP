/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:03:19 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/18 09:35:25 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		RPN calculation;
		calculation.parse(argv[1]);
	}
	else
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
