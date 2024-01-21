/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:17:14 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/20 16:22:44 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <cfloat>
#include <iomanip>

class ScalarConverter
{
	public:
		static void convert(const std::string& literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		static void convertToChar(double value);
		static void convertToInt(double value);
		static void convertToFloat(double value);
		static void handleAndPrintConvertedValue(const std::string& type, double value);
		static void printValue(const std::string& type, const std::string& value);
		static bool isPseudoLiteral(const std::string& literal);
		static double stringToDouble(const std::string& literal);
};

#endif
