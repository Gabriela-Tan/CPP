/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:03:19 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/25 08:12:53 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
	PmergeMe merge;
	std::vector<int> input;

	for (int i = 1; i < argc; ++i)
	{
		if (isValid(argv[i]))
			input.push_back(atoi(argv[i]));
		else
		{
			std::cerr << "Invalid input!" << std::endl;
			return 1;
		}
	}
	merge.printOutput(input);
	return 0;
}

// linux input: `shuf -i 1-1000 -n 3000 | tr "\n" " " `
// mac input: `jot -r 3000 1 1000 | tr '\n' ' '`