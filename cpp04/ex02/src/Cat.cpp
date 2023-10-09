/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:20:00 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/09 12:25:08 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "Cat Constructor called" << std::endl;
	this->_type = "Cat";
	try {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "ENOMEM: " << e.what() << std::endl;
    }
}

Cat::~Cat(){
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat& cpy) : AAnimal(cpy){
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = cpy;
}

Cat& Cat::operator=(const Cat& cpy)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &cpy)
	{
        _type = cpy._type;
		this->_brain = new Brain( *cpy._brain );
	}
    return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Miiaaaauuuuuuu ffffffffffff * se pone agresivo *" << std::endl;
}
