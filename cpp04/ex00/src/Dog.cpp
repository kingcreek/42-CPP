/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:24:00 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/03 10:08:28 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog Constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog(){
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy){
	this->_type = cpy._type;
	*this = cpy;
}

Dog& Dog::operator=(const Dog& cpy)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &cpy)
    {
        _type = cpy._type;
    }
    return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Guau Guau Guau * corre tras el gato *" << std::endl;
}