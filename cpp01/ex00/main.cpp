/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:09:01 by imurugar          #+#    #+#             */
/*   Updated: 2023/04/30 04:00:00 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string name;
	
	std::cout << "---HEAP---" << std::endl;
	std::cout << "Name: " << std::flush;
	std::cin >> name;
	Zombie *zombie = newZombie(name);
	zombie->announce();
	delete zombie;
	
	std::cout << "---STACK---" << std::endl;
	std::cout << "Name: " << std::flush;
	std::cin >> name;
	randomChump(name);
	
	
}