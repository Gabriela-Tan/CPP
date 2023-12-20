/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:35:09 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/06 14:38:17 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap has been created by default constructor." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been created by constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), 
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " is created by copy constructor." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "Copy assignment operator is being called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is destructed." << std::endl;
}

void
ClapTrap::attack(const std::string& target) 
{
	if (_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot do anything if is has no HP or EP left." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void
ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot take more damage, leave it alone!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " says \"Ouch!\", taking " << amount << " points of damage!" << std::endl;
	_hitPoints = (amount > _hitPoints) ? 0 : _hitPoints - amount;
}

void
ClapTrap::beRepaired(unsigned int amount)
	{
	if (_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy or hit points to repair itself!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}

unsigned int
ClapTrap::showEnergyPoints() const
{
	return _energyPoints;
}

unsigned int
ClapTrap::showHitPoints() const
{
	return _hitPoints;
}

void
ClapTrap::showStatus() const
{
	std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points and " << _energyPoints << " energy points." << std::endl;
}
