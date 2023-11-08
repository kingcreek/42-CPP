/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:03:12 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/17 16:43:18 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal& cpy)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = cpy;
}

Animal::~Animal(){
	std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& cpy)
{
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &cpy)
        this->_type = cpy._type;
    return *this;
}

std::string const& Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
    std::cout << "No hay ningún tipo de sonido..." << std::endl;
}
