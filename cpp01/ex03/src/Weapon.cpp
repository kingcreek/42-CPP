/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:13:17 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/14 15:58:43 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : type(type) {}

Weapon::~Weapon( void ) {}

const std::string&	Weapon::getType( void ) const {
	return (this->type);
}

bool Weapon::setType( const std::string& newType ) {
	if (newType.empty())
	{
		std::cout << "new type can't be empty string" << std::endl;
		return (false);
	}
	this->type = newType;
	return (true);
}
