/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:09:05 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/09 11:15:19 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog& cpy);
		Dog& operator=(const Dog& cpy);
		~Dog();
		
		void makeSound(void) const;

	private:
		Brain* _brain;
	
};

#endif
