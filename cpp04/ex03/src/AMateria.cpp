/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:01:44 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/17 15:25:15 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("")
{
    // std::cout << "* AMateria: materia is created *" << std::endl;
}

AMateria::AMateria( std::string const & type )  : _type(type)
{
    std::cout << "AMateria " << this->_type << " created" << std::endl;
}

AMateria::AMateria( AMateria const & src )
{
    *this = src;
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria " << this->_type << " destroyed" << std::endl;
}

AMateria& AMateria::operator=( AMateria const & rhs )
{
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

AMateria* AMateria::clone() const
{
    return (AMateria*)this;
}

void    AMateria::use( ICharacter& target )
{
    std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}

void	AMateria::setState(bool state) {
	this->_state = state;
}

bool	AMateria::getState(void) const {
	return this->_state;
}
