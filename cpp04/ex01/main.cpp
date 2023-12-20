/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:34:57 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/20 11:17:14 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Testing animal creation and deletion" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
	// should not create a leak
		delete j;
		delete i;
	}

	std::cout << "\nCreating individual animals and their deep copies" << std::endl;
	{
		Dog dogBasic;
		Dog dogCopy = dogBasic;  // Using copy constructor
		Dog dogAssigned;
		dogAssigned = dogBasic;  // Using copy assignment operator

		Cat catBasic;
		Cat catCopy = catBasic;  // Using copy constructor
		Cat catAssigned;
		catAssigned = catBasic;  // Using copy assignment operator

		// Animal array
		const int numAnimals = 4;
		Animal* animals[numAnimals];
		int i = 0;
		while (i < numAnimals / 2)
		{
			animals[i] = new Dog();
			i++;
		}
		while (i < numAnimals)
		{
			animals[i] = new Cat();
			i++;
		}

		// Show brain address for all animals
		std::cout << "\nTesting that each cat/dog has it's own brain:" << std::endl;
		dogBasic.brainAddress();
		dogCopy.brainAddress();
		dogAssigned.brainAddress();
		catBasic.brainAddress();
		catCopy.brainAddress();
		catAssigned.brainAddress();

		std::cout << "\nTesting animals in array:" << std::endl;
		i = 0;
		while (i < numAnimals)
		{
			animals[i]->brainAddress();
			i++;
		}

		// Clean up
		std::cout << "\nDeleting animals:" << std::endl;
		i = 0;
		while (i < numAnimals)
		{
			delete animals[i];
			i++;
		}
	}

	return 0;
}
