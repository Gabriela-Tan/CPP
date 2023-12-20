/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:34:57 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/06 14:47:12 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Clap("Clap");
	ClapTrap Trap("Trap");

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

	return 0;
}
