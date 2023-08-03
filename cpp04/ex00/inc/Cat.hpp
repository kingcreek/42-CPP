/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:08:24 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/03 09:57:51 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
	
	private:
	
	public:
		Cat();
		Cat(const Cat& cpy);
		Cat& operator=(const Cat& cpy);
		~Cat();
		
		void makeSound(void) const;

	
};