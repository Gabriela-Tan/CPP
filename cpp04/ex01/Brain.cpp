/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:06:30 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/17 09:05:23 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	handleIdeas(other);
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		std::cout << "Brain copy assignment operator called" << std::endl;
		handleIdeas(other);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void
Brain::handleIdeas(const Brain& other)
{
	int i = 0;
	while (i < 100)
	{
		ideas[i] = other.ideas[i];
		++i;
	}
}
