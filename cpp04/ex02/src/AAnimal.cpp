/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:03:12 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/09 10:59:24 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& cpy)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = cpy;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& cpy)
{
    std::cout << "AAnimal assignation operator called" << std::endl;
    if (this != &cpy)
        this->_type = cpy._type;
    return *this;
}

std::string const& AAnimal::getType() const {
	return this->_type;
}

void AAnimal::makeSound() const {
    std::cout << "No hay ningún tipo de sonido..." << std::endl;
}
		