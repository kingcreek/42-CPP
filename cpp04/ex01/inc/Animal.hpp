/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:08:21 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/09 12:21:07 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal
{	
	public:
		Animal(void);
		Animal(const Animal& cpy);
		Animal& operator=(const Animal& cpy);
		virtual ~Animal();
		
		std::string const& getType(void) const;
		virtual void makeSound() const;

	protected:
		std::string _type;
		
};

#endif
