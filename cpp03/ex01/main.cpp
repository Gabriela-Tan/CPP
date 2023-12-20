/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:34:57 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/06 15:12:26 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap Clap("Clap");
	ClapTrap Trap("Trap");

	std::cout << "Testing ClapTrap:" << std::endl;
	Clap.showStatus();
	Trap.showStatus();

	while (Clap.showEnergyPoints() > 0)
	{
		Clap.attack("Trap");
		Trap.takeDamage(0);
	}

	Clap.showStatus();
	Trap.showStatus();

	Clap.attack("Trap");

	Trap.beRepaired(5);
	Trap.showStatus();

	std::cout << "\nTesting ScavTrap:" << std::endl;
	ScavTrap Scav("Scav");
	Scav.showStatus();

	Scav.attack("Trap");
	Trap.takeDamage(20);

	Scav.showStatus();
	Trap.showStatus();

	Scav.attack("Trap");
	Trap.takeDamage(20);
	Trap.showStatus();
	Trap.attack("Scav");

	Scav.guardGate();

	Scav.beRepaired(5);
	Scav.showStatus();

	return 0;
}
