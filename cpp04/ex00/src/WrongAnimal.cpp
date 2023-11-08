/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:02:01 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/17 16:43:30 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown Beast")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & cpy)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = cpy;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & cpy)
{
	std::cout << "WrongAnimal assignment overload operator called." << std::endl;
	if (this != &cpy)
		this->_type = cpy._type;
	return (*this);
}

std::string const& WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "* Indescribable sound *" << std::endl;
}
