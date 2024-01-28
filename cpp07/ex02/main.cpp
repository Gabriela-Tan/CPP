/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:16:14 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/28 10:49:30 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 10
int main(void)
{
	Array<int> emptyArray;
	std::cout << "Empty array created, size: " << emptyArray.size() << std::endl;

	Array<int> numbers(MAX_VAL);
	std::cout << "Creating an array of size: " << numbers.size() << std::endl;
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));

	std::cout << "Initial values in the array after default construction" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}

	std::cout << "\nFilling the array and mirror with random values" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() % 100;
		numbers[i] = value;
		mirror[i] = value;
		std::cout << "numbers[" << i << "] = " << numbers[i] << ", mirror[" << i << "] = " << mirror[i] << std::endl;
	}

	std::cout << "\nTesting copy construction and assignment operator" << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test;
		test = tmp;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << "tmp [" << i << "] = " << tmp[i] << std::endl;
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << "test [" << i << "] = " << test[i] << std::endl;
		}
	}

	std::cout << "\nChecking if the original Array and mirror have the same values" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
		}
		std::cout << "numbers[" << i << "] = " << numbers[i] << ", mirror[" << i << "] = " << mirror[i] << std::endl;
	}

	std::cout << "\nTesting out-of-range access with negative index" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	std::cout << "\nTesting out-of-range access with index 1 place beyond the array scope" << std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}

	std::cout << "\nCreating an array of arrays of ints" << std::endl;
	Array<Array<int> > arrayOfArrays(MAX_VAL);

	std::cout << "Filling the array of arrays with ints" << std::endl;
	for (unsigned int i = 0; i < arrayOfArrays.size(); ++i)
	{
		Array<int> tempArray(2);
		std::cout << "Made Array " << i << " with values ";
		for (unsigned int j = 0; j < tempArray.size(); ++j)
		{
			tempArray[j] = (i + 1);
			std::cout << tempArray[j] << " ";
		}
		arrayOfArrays[i] = tempArray;
		std::cout << std::endl;
	}

	std::cout << "\nRead-only access for const array" << std::endl;
	const Array<int> constIntArray(3);
	for (int i = 0; i < 3; i++)
	{
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}
	// Writing to const array will cause compilation error:
	//	 constIntArray[0] = 20;

	delete [] mirror;
	std::cout << "We're done here!" << std::endl;
	return 0;
}
