/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:37:17 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/08 10:27:37 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		FragTrap e("Dwayne Johnson");
		FragTrap f("Chuck Norris");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		e.highFivesGuys();
		e.attack("Chuck Norris");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("Chuck Norris");
		f.highFivesGuys();

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	
	return (0);
}
