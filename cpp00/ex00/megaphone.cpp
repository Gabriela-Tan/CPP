/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:55:41 by gabriela          #+#    #+#             */
/*   Updated: 2023/11/17 15:18:52 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int i = 1;
		while (i < argc)
		{
			char *arg = argv[i];
			int j = 0;
			while (arg[j] != '\0')
			{
				std::cout << (char)std::toupper(arg[j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
