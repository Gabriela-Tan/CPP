/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:42:13 by gabriela          #+#    #+#             */
/*   Updated: 2023/11/26 12:14:37 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Input: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return -1;
	}
	StrReplacer replacer(argv[1], argv[2], argv[3]);
	if (replacer.transform() == -1)
		return -1;
	return 0;
}