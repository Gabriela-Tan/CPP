/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:00:05 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/17 15:29:27 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type), _brain(new Brain())
{
	_type = type;
	std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		Brain* newBrain = new Brain(*other._brain);
		delete _brain;
		_brain = newBrain;
		std::cout << "Cat copy assignment operator called" << std::endl;

	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void
Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void
Cat::brainAddress() const 
{
	if (_brain)
		std::cout << "Cat brain address: " << _brain << std::endl;
}
