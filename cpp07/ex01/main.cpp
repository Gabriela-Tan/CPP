/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:02:16 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/27 11:06:39 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main()
{
	// Int array
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
	iter(intArray, intSize, printElement);

	// Double array
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
	iter(doubleArray, doubleSize, printElement);

	// Char array
	char charArray[] = {'A', 'B', 'C', 'D', 'E'};
	size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
	iter(charArray, charSize, printElement);

	// String array
	std::string stringArray[] = {"This", "is", "totally", "outstanding", "project"};
	size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
	iter(stringArray, stringSize, printElement);

	return 0;
}
