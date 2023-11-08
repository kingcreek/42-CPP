/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:08:21 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/09 12:21:07 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP


#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal
{	
	public:
		AAnimal(void);
		AAnimal(const AAnimal& cpy);
		AAnimal& operator=(const AAnimal& cpy);
		virtual ~AAnimal();
		
		std::string const& getType(void) const;
		virtual void makeSound() const = 0; //pure virtual, make abstract class

	protected:
		std::string _type;
		
};

#endif
