/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:37:17 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/08 10:27:42 by imurugar         ###   ########.fr       */
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
		
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		DiamondTrap diamondTrap(diamondTrapName);
		ScavTrap scavTrap(scavTrapName);
		ClapTrap clapTrap(clapTrapName);
		
		std::cout << "\033[34mTesting\033[0m" << std::endl;
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

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}

	return (0);
}
