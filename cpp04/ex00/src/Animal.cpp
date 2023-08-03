/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:03:12 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/03 09:48:33 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal Constructor called" << std::endl;
	this->type = "Animal";
}

Animal::~Animal(){
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& cpy){
	*this = cpy;
}

Animal& Animal::operator=(const Animal& cpy)
{
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &cpy)
    {
        type = cpy.type;
    }
    return *this;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
    std::cout << "No hay ningún tipo de sonido..." << std::endl;
}
		