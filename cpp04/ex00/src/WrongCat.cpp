/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:03:18 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/03 10:10:02 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal() 
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called." << std::endl;
	return ;
}

WrongCat &	WrongCat::operator=(WrongCat const & src)
{
	std::cout << "WrongCat assignment overload operator called." << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong Miiaaaauuuuuuu ffffffffffff * se pone agresivo *" << std::endl;
	return ;
}