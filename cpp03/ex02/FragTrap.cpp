/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:41:33 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/10 08:59:44 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Frag")
{
	std::cout << "FragTrap has been created by default constructor." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created by constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap " << _name << " is created by copy constructor." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator is being called." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is destructed." << std::endl;
}

void
FragTrap::attack(const std::string& target)
{
	if (_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " cannot do anything if it has no HP or EP left." << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void
FragTrap::highFivesGuys(void)
{
	std::cout << "Positive high five request on standard output." << std::endl;
}
