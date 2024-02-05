/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:24:56 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/05 13:24:38 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	std::cout << "Testing mutant stack with integers: " << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Current top element: " << mstack.top() << std::endl; // 17, 5

	mstack.pop();
	std::cout << "Size after removing one element: " << mstack.size() << std::endl; // 5

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	std::cout << "Stack after adding more elements: " << std::endl; // 0, 737, 5, 3, 5
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	while (!mstack.empty())
		mstack.pop();
	std::cout << "The integer stack is empty now." << std::endl;

	std::cout << "\nReplacing MutantStack with std::list: " << std::endl;
	std::cout << "Testing list with integers: " << std::endl;
	std::list<int> normalList;

	normalList.push_back(5);
	normalList.push_back(17);

	std::cout << "Current top element: " << normalList.back() << std::endl;

	normalList.pop_back();
	std::cout << "Size after removing one element: " << normalList.size() << std::endl;

	normalList.push_back(3);
	normalList.push_back(5);
	normalList.push_back(737);
	normalList.push_back(0);

	std::cout << "List after adding more elements: " << std::endl;
	for (std::list<int>::iterator it = normalList.begin(); it != normalList.end(); ++it)
		std::cout << *it << std::endl;

	while (!normalList.empty())
		normalList.pop_back();
	std::cout << "The integer list is empty now." << std::endl;

 	// Test with std::string
	std::cout << "\nTesting mutant stack with strings: " << std::endl;
	MutantStack<std::string> stringStack;

	stringStack.push("This");
	stringStack.push("is");
	stringStack.push("totally");
	stringStack.push("outstanding");
	stringStack.push("project");

	std::cout << "Iterating over the string stack: " << std::endl;
	for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it)
		std::cout << *it << std::endl;

	return 0;
}