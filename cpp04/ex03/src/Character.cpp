/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:01:54 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/17 16:33:00 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string const & name ) : _name(name)
{
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    std::cout << "Character " << this->_name << " created" << std::endl;
}

Character::Character( Character const & src ) : _name(src._name)
{
    // for (int i = 0; i < 4; i++)
    //     this->_inventory[i] = src._inventory[i];
    *this = src;
    std::cout << "Character " << this->_name << " created" << std::endl;
}

Character& Character::operator=( Character const & rhs )
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        for (int i = 0; i < 4; i++) 
            this->_inventory[i] = rhs._inventory[i];
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character " << this->_name << " destroyed" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_inventory[i])
            delete this->_inventory[i];
}

void    Character::equip( AMateria* m ) {
	if (m)
	{
    	for (int i = 0; i < 4; i++)
		{
        	if (this->_inventory[i] == NULL)
        	{
				if (m->getState() == true)
				{
					std::cout << "Materia already equipped." << std::endl;
            		return;
				}
            	this->_inventory[i] = m;
				m->setState(true);
            	std::cout << "Character " << this->_name << " equipped with " << m->getType() << std::endl;
            	return;
        	}
		}
		std::cout << "Character " << this->_name << " can't equip " << m->getType() << std::endl;
	}
    std::cout << "Materia doesn't exist" << std::endl;
}

void    Character::unequip( int idx ) {
    if (idx >= 0 && idx <= 3 && this->_inventory[idx])
    {
		this->_inventory[idx]->setState(false);
        this->_inventory[idx] = NULL;
        std::cout << "Character " << this->_name << " unequipped" << std::endl;
    }
    else
        std::cout << "Character " << this->_name << " can't unequip" << std::endl;
}

void    Character::use( int idx, ICharacter& target ) {
    if (idx >= 0 && idx <= 3 && this->_inventory[idx])
    {
        this->_inventory[idx]->use(target);
        std::cout << "Character " << this->_name << " uses " << this->_inventory[idx]->getType() << std::endl;
    }
    else
        std::cout << "Character " << this->_name << " can't use" << std::endl;
}

std::string const& Character::getName() const {
    return this->_name;
}
