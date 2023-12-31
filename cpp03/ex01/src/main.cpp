/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:37:17 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/08 09:51:21 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ScavTrap c("Dwayne Johnson - clon");
		ScavTrap d("Chuck Norris - clon");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		c.attack("Chuck Norris - clon");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Dwayne Johnson - clon");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("Dwayne Johnson - clon");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
}
