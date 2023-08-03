/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:20:00 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/03 10:08:21 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat Constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat(){
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy){
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = cpy;
}

Cat& Cat::operator=(const Cat& cpy)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &cpy)
    {
        _type = cpy._type;
    }
    return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Miiaaaauuuuuuu ffffffffffff * se pone agresivo *" << std::endl;
}