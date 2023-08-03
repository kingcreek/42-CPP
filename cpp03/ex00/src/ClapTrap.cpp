/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:37:24 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/02 15:34:18 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap constructor with arguments called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target){
	if (_energy_points <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
		return;
	}
	if (_hit_points <= 0) {
		std::cout << "ClapTrap " << _name << " tries to attack, but we haven't implemented zombie attacks... yet" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	_energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	if(_hit_points <= 0){
		std::cout << "ClapTrap " << this->_name << " he's already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " take " << amount << " of damage!" << std::endl;
	_hit_points -= amount;
	if(_hit_points <= 0)
		std::cout << "ClapTrap " << this->_name << " has died, let us pray" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energy_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy to repair!" << std::endl;
        return ;
    }
	if (_hit_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " tries to repair, but he hasn't realized that he's already dead, nice try." << std::endl;
        return ;
    }
	if (_hit_points >= 10)
	{
		std::cout << "ClapTrap " << _name << " already has life to the fullest" << std::endl;
		return ;
	}
	if (_hit_points + amount > 10)
    {
        std::cout << "ClapTrap " << _name << " has max hitpoints!" << std::endl;
        _hit_points = 10;
		_energy_points -= 1;
        return ;
    }
    std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
    _hit_points += amount;
    _energy_points -= 1;
}