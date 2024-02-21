/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:03:19 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/17 12:47:19 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange bitcoin;
			bitcoin.loadData("data.csv");
			bitcoin.processInput(argv[1]);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
		}
	}
	else
	{
		std::cerr << "Error! Wrong arguments." << std::endl;
		return 1;
	}
	return 0;
}
