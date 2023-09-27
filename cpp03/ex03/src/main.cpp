/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:37:17 by imurugar          #+#    #+#             */
/*   Updated: 2023/09/27 02:38:45 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n\n### TESTING DIAMOND ###\n" << std::endl;
	{
		std::string diamondTrapName = "DT-XXY";
		std::string scavTrapName = "SCVT-2000";
		std::string clapTrapName = "CT-42";

		DiamondTrap diamondTrap(diamondTrapName);
		ScavTrap scavTrap(scavTrapName);
		ClapTrap clapTrap(clapTrapName);

		diamondTrap.whoAmI();
		clapTrap.attack(scavTrapName);
		scavTrap.takeDamage(0);
		scavTrap.attack(clapTrapName);
		clapTrap.takeDamage(20);
		diamondTrap.attack(scavTrapName);
		scavTrap.takeDamage(30);
		diamondTrap.highFivesGuys();
		diamondTrap.guardGate();
		diamondTrap.takeDamage(5000);
		diamondTrap.beRepaired(5000);
		diamondTrap.whoAmI();
	}

	return (0);
}
