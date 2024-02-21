/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:03:15 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/17 13:15:01 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <cstdlib>
#include <stdexcept>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_rate;

		void	dateHandler(const std::string& date);
		void	valueHandler(std::string value, int flag);
	
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		~BitcoinExchange();
		
		void	loadData(const std::string& fileName);
		void	processInput(const std::string fileName);
};

#endif