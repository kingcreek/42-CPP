/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:37:17 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/02 16:53:52 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a("Dwayne Johnson");
		ClapTrap b("Chuck Norris");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("Chuck Norris");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("Chuck Norris");
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
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
/*  highFivesGuys
int main()
{
	ClapTrap war1("Dwayne Johnson");
	ClapTrap war2("Chuck Norris");
	
	war1.attack("Chuck Norris");
	war2.takeDamage(0);
	war2.beRepaired(100000);
    
	war2.attack("Dwayne Johnson");
	war2.takeDamage(0);
	war2.beRepaired(1);
	
    return 0;
}
*/