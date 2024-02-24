/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtan <gabtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:03:12 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/24 15:04:46 by gabtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other):
	_rate(other._rate)
{}

BitcoinExchange&
BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_rate = other._rate;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void
BitcoinExchange::loadData(const std::string& fileName)
{
	std::string row;
	std::ifstream csv(fileName.c_str());
	if (!csv.is_open())
		throw std::runtime_error("Error! Cannot open the csv file: " + fileName);
	if (!std::getline(csv, row) || row != "date,exchange_rate")
		throw std::runtime_error("Error! The content of the csv file is invalid: " + fileName);
	
	while (std::getline(csv, row))
	{
		std::string date, value;
		std::stringstream stream(row);
		std::getline(stream, date, ',');
		std::getline(stream, value);
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
		value.erase(std::remove(value.begin(), value.end(), ' '), value.end());

		if (!date.empty() && !value.empty())
		{
			dateHandler(date);
			valueHandler(value, 0);
			_rate.insert(std::make_pair(date, std::strtod(value.c_str(), NULL)));
		}
	}
	csv.close();
}

void
BitcoinExchange::dateHandler(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("Invalid date format: " + date);

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
		throw std::invalid_argument("Invalid date: " + date);

	bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	int daysInMonth[] = {31, isLeapYear ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (day > daysInMonth[month - 1])
		throw std::invalid_argument("Invalid date: " + date);
}


void
BitcoinExchange::valueHandler(std::string value, int flag)
{
	char	*terminator;
	double	number = strtod(value.c_str(), &terminator);

	if (*terminator != '\0')
		throw std::invalid_argument("bad input => " + value);
	if (number < 0)
		throw std::invalid_argument("not a positive number");
	if (number > 1000 && flag == 1)
		throw std::invalid_argument("too large a number.");
}

void
BitcoinExchange::processInput(const std::string fileName)
{
	std::string row;
	std::ifstream input(fileName.c_str());
	if (!input.is_open())
		throw std::runtime_error("Cannot open the input file: " + fileName);
	if (!std::getline(input, row) || row != "date | value")
		throw std::runtime_error("The input file is invalid.");
		
	while (std::getline(input, row)) 
	{
		try
		{
			std::string date, value, rest;
			std::stringstream stream(row);
			std::getline(stream, date, '|');
			std::getline(stream, rest);
			date = date.erase(date.find_last_not_of(" \n\r\t")+1);
			date = date.erase(0, date.find_first_not_of(" \n\r\t"));
			rest = rest.erase(rest.find_last_not_of(" \n\r\t")+1);
			rest = rest.erase(0, rest.find_first_not_of(" \n\r\t"));
			if (date.empty())
				throw std::invalid_argument("Missing date in input");
			if (rest.empty())
				throw std::invalid_argument("bad input => " + date);
			value = rest;

			dateHandler(date);
			valueHandler(value, 1);

			std::map<std::string, double>::iterator it = _rate.lower_bound(date);
			if (it != _rate.begin() && (it == _rate.end() || it->first != date))
				--it;
			if (it != _rate.end())
			{
				double rate = it->second;
				std::cout << date << " => " << value << " = " << rate * std::strtod(value.c_str(), NULL) << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	input.close();
}
