/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:42:27 by gabriela          #+#    #+#             */
/*   Updated: 2023/11/26 11:16:27 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class StrReplacer
{
	public:
		StrReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
		int transform();

	private:
		std::string _filename;
		std::string _searchStr;
		std::string _replaceStr;
		std::string replacing(std::string content, const std::string& srcStr, const std::string& dest);
};

#endif
