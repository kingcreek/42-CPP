/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:09:05 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/03 09:57:57 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
	
	private:
	
	public:
		Dog();
		Dog(const Dog& cpy);
		Dog& operator=(const Dog& cpy);
		~Dog();
		
		void makeSound(void) const;

	
};