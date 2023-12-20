/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:00:21 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/17 10:46:04 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type),  _brain(new Brain())
{
	_type = type;
	std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		Brain* newBrain = new Brain(*other._brain);
		delete _brain;
		_brain = newBrain;
		std::cout << "Dog copy assignment operator called" << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void
Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

void 
Dog::brainAddress() const 
{
	if (_brain)
		std::cout << "Dog brain address: " << _brain << std::endl;
}
