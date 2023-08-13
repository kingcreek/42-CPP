/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:13:11 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/13 18:04:06 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ): name(name), weapon(weapon) {}

HumanA::~HumanA( void ) {}

void HumanA::attack( void ) const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

Weapon& HumanA::getWeapon( void ) const
{
	return (this->weapon);
}