/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:24:00 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/09 11:38:30 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog Constructor called" << std::endl;
	this->_type = "Dog";
	try {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "ENOMEM: " << e.what() << std::endl;
    }
}

Dog::~Dog(){
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
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
		this->_brain = new Brain( *cpy._brain );
	}
    return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Guau Guau Guau * corre tras el gato *" << std::endl;
}