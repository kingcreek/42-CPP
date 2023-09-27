/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 00:37:23 by imurugar          #+#    #+#             */
/*   Updated: 2023/09/27 02:35:17 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap() {}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 30;

    std::cout << "Sub Class (DiamondTrap) constructor has been called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original)
: ClapTrap(original), FragTrap(original), ScavTrap(original)
{
	*this = original;
	std::cout << "Sub Class (DiamondTrap) copy constructor has been called" << std::endl; 
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
	this->name = original.name;
	ClapTrap::_name = (this->name + "_clap_name");
	this->_hit_points = original._hit_points;
	this->_energy_points = original._energy_points;
	this->_attack_damage = original._attack_damage;

	std::cout << "Sub Class (DiamondTrap) Assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "Sub Class (DiamondTrap) destructor has been called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "I AM:\nDiamondTrap: " << this->name << "\nClapTrap: " << ClapTrap::_name << std::endl;
}