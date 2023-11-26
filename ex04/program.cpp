/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:42:22 by gabriela          #+#    #+#             */
/*   Updated: 2023/11/26 12:13:54 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

StrReplacer::StrReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
	: _filename(filename), _searchStr(s1), _replaceStr(s2) {}

int
StrReplacer::transform()
{
	std::ifstream inFile(_filename);
	if (!inFile)
	{
		std::cerr << "Error: Unable to open file." << std::endl;
		return -1;
	}

	std::stringstream buffer;
	buffer << inFile.rdbuf();
	std::string content = buffer.str();
	inFile.close();

	if (content.find(_searchStr) == std::string::npos)
	{
		std::cerr << "Error: String not found." << std::endl;
		return -1;
	}

	std::string newContent = replacing(content, _searchStr, _replaceStr);

	std::ofstream outFile(_filename + ".replace");
	if (!outFile)

	{
		std::cerr << "Error: Unable to create file." << std::endl;
		return -1;
	}

	outFile << newContent;
	outFile.close();
	return 0;
}

std::string
StrReplacer::replacing(std::string content, const std::string& srcStr, const std::string& destStr)
{
	size_t start = 0;
	while ((start = content.find(srcStr, start)) != std::string::npos)
	{
		content = content.substr(0, start) + destStr + content.substr(start + srcStr.length());
		start += destStr.length();
	}
	return content;
}
