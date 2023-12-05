/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:19:20 by gabriela          #+#    #+#             */
/*   Updated: 2023/11/26 12:48:05 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl HarlInstance;

	HarlInstance.complain("DEBUG");
	HarlInstance.complain("INFO");
	HarlInstance.complain("WARNING");
	HarlInstance.complain("ERROR");
	HarlInstance.complain("SOMETHING");

	return 0;
}
