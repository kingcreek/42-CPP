/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:13:13 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/13 18:03:59 by imurugar         ###   ########.fr       */
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

void HumanB::attack( void ) const
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " can't attack because they don't have a weapon" << std::endl;
}

void HumanB::setWeapon( Weapon& newWeapon )
{
	if (newWeapon.getType().empty())
	{
		std::cerr << "New weapon can't be nothing" << std::endl;
		return ;
	}
	this->weapon = &newWeapon;
}