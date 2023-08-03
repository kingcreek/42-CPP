/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:13:13 by imurugar          #+#    #+#             */
/*   Updated: 2023/07/31 08:50:41 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB( std::string name ): name(name)
{
	this->weapon = NULL;
}

HumanB::~HumanB( void )
{
}

void	HumanB::attack( void ) const
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " can't attack because they don't have a weapon" << std::endl;
}

bool	HumanB::setWeapon( Weapon& newWeapon )
{
	if (newWeapon.getType() == "")
	{
		std::cerr << "New weapon can't be nothing" << std::endl;
		return (false);
	}
	this->weapon = &newWeapon;
	return (true);
}