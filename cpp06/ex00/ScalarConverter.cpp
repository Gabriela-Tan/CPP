/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:47:06 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/20 17:45:59 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter&
ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

void
ScalarConverter::convert(const std::string& literal)
{
	if (isPseudoLiteral(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (literal == "+inf" || literal == "-inf")
		{
			printValue("float", literal + "f");
			printValue("double", literal);
		}
		else if (literal.find('f') != std::string::npos)
		{
			printValue("float", literal);
			printValue("double", literal.substr(0, literal.size() - 1));
		}
		else
		{
			printValue("float", literal + "f");
			printValue("double", literal);
		}
		return;
    }

	if (literal.length() == 1 && isdigit(literal[0]))
	{
		std::istringstream stream(literal);
		double value;
		stream >> value;

		convertToChar(value);
		convertToInt(value);
		convertToFloat(value);
		handleAndPrintConvertedValue("double", value);
		return;
	}
	else if (literal.length() == 1 && std::isprint(literal[0]))
	{
		double value = static_cast<double>(literal[0]);
		std::cout << "char: " << literal[0] << std::endl;
		convertToInt(value);
		convertToFloat(value);
		handleAndPrintConvertedValue("double", value);
		return;
	}

	std::string processed = literal;
	if (literal.find('f') != std::string::npos)
		processed = literal.substr(0, literal.size() - 1);

	std::istringstream stream(processed);
	double value;
	if (!(stream >> value))
	{
		std::cout << "Input not valid" << std::endl;
		return;
	}

	convertToChar(value);
	convertToInt(value);
	convertToFloat(value);
	handleAndPrintConvertedValue("double", value);
}

void
ScalarConverter::convertToChar(double value)
{
	if (value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max()
		|| std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	int intValue = static_cast<int>(value);

	if (intValue < std::numeric_limits<char>::min()
		|| intValue > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else
	{
		char charValue = static_cast<char>(intValue);
		if (std::isprint(charValue))
			std::cout << "char: '" << charValue << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

void
ScalarConverter::convertToInt(double value)
{
	if (value < std::numeric_limits<int>::min()
	|| value > std::numeric_limits<int>::max()
	|| std::isnan(value) || std::isinf(value))
		std::cout << "int: impossible" << std::endl;
	else
	{
		int intValue = static_cast<int>(value);
		std::cout << "int: " << intValue << std::endl;
	}
}

void
ScalarConverter::convertToFloat(double value)
{
	if (std::isnan(value) || std::isinf(value))
		handleAndPrintConvertedValue("float", value);
	else
	{
		float floatValue = static_cast<float>(value);
		std::ostringstream stream;
		stream << std::fixed << std::setprecision(1) << floatValue << 'f';
		std::cout << "float: " << stream.str() << std::endl;
	}
}

void
ScalarConverter::handleAndPrintConvertedValue(const std::string& type, double value)
{
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(1);
	if (std::isnan(value))
		stream << "nan";
	else if (std::isinf(value))
		stream << (value < 0 ? "-" : "") << "inf";
	else
		stream << value;

	if (type == "float")
		stream << 'f';

	std::cout << type << ": " << stream.str() << std::endl;
}

void
ScalarConverter::printValue(const std::string& type, const std::string& value)
{
	std::cout << type << ": " << value;
	std::cout << std::endl;
}

bool
ScalarConverter::isPseudoLiteral(const std::string& literal)
{
	return literal == "-inff"
		|| literal == "+inff"
		|| literal == "nanf"
		|| literal == "-inf"
		|| literal == "+inf"
		|| literal == "nan";
}

double
ScalarConverter::stringToDouble(const std::string& literal)
{
	std::istringstream stream(literal);
	double value;
	if (!(stream >> value))
		value = 0.0;
	return value;
}
