/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:02:01 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/03 10:09:44 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Unknown Beast")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = src;
	return ;
}

WrongAnimal::WrongAnimal(std::string const & type) : _type(type)
{
	std::cout << "WrongAnimal type constructor called." << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called." << std::endl;
	return ;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src)
{
	std::cout << "WrongAnimal assignment overload operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const &	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "* Sonido indescriptible *" << std::endl;
}