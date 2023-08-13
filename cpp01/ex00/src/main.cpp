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

/*
Personalmente no me parece correcto que las funciones newZombie y randomChump hayan de ser
globales para poder acceder a ellas ya que están directamente relacionadas con la clase
Zombie, personalmente usaria static en ambas para que sean inherentes a ella.
Hacer esto cambiaria el constructor a Zombie* Zombie::newZombie(std::string)
lo cual no cumpliria con el subject... asi que... keep calm and dejalo así
*/
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