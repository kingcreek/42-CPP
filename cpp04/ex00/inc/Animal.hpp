/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:08:21 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/03 10:05:56 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal
{
	
	private:
	
	public:
		Animal();
		Animal(const Animal& cpy);
		Animal& operator=(const Animal& cpy);
		virtual ~Animal();
		
		std::string getType(void) const;
		virtual void makeSound() const;

	protected:
		std::string _type;
		
};