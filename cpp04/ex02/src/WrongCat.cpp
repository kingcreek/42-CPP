/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:03:18 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/17 16:45:31 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal()  {
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = src;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat &	WrongCat::operator=(WrongCat const & cpy)
{
	std::cout << "WrongCat assignment overload operator called." << std::endl;
	if (this != &cpy)
		this->_type = cpy._type;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "Wrong Miiaaaauuuuuuu ffffffffffff * se pone agresivo *" << std::endl;
}
