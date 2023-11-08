/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:09:37 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/17 16:45:52 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& cpy){
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = cpy;
}

Brain& Brain::operator=(const Brain& cpy)
{
    std::cout << "Brain assignation operator called" << std::endl;
     if (this != &cpy)
	 {
		size_t length = sizeof(_ideas) / sizeof(_ideas[0]);
		for (size_t i = 0; i < length; i++)
			_ideas[i] = cpy._ideas[i];
	 }
    return *this;
}
