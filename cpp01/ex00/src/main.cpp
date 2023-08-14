/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:09:01 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/13 13:48:58 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	{
		std::cout << "---HEAP---" << std::endl;
		std::cout << "Name: Zombie 1" << std::endl;
		Zombie *zombie = newZombie("Zombie 1");
		zombie->announce();
		delete zombie;
	}

	{
		std::cout << "---STACK---" << std::endl;
		std::cout << "Name: Zombie 2" << std::endl;
		randomChump("Zombie 2");
		return (0);
	}
}
