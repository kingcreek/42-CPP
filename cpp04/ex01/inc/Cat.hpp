/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:08:24 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/09 11:17:51 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& cpy);
		Cat& operator=(const Cat& cpy);
		~Cat();
		
		void makeSound(void) const;
	
	private:
		Brain* _brain;
	
};

#endif
