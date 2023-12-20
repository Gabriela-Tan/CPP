/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:34:57 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/20 09:27:41 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	std::cout << "Cat makes sound: " << std::endl;
	i->makeSound();
	std::cout << "Dog makes sound: " << std::endl;
	j->makeSound();
	std::cout << "Animal makes sound: " << std::endl;
	meta->makeSound();

	const WrongCat* wrongCat = new WrongCat();
	const WrongAnimal* wrongCatAsWrongAnimal = wrongCat;

	std::cout << wrongCat->getType() << std::endl;
	std::cout << wrongCatAsWrongAnimal->getType() << std::endl;

	std::cout << "WrongCat as WrongCat makes sound: " << std::endl;
	wrongCat->makeSound();
	std::cout << "WrongCat as WrongAnimal makes sound: " << std::endl;
	wrongCatAsWrongAnimal->makeSound();

	delete i;
	delete j;
	delete meta;
	delete wrongCat;
	// No need to delete wrongCatAsWrongAnimal, it points to the same object as wrongCat

	return 0;
}
