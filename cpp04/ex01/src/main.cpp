/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:42:39 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/17 16:44:07 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
	{
    	const Animal* j = new Dog();
    	const Animal* i = new Cat();

    	delete j;//should not create a leak
    	delete i;
	}

	{
    	Dog basic;
		Dog tmp = basic;
	}

	{
    	const Animal* animals[] = { new Dog(), new Dog(), new Cat(), new Cat(), new Cat(), new Dog() };
		size_t numElements = sizeof(animals) / sizeof(animals[0]);
    	for ( size_t i = 0; i < numElements; i++ ) {
			delete animals[i];
    	}
	}

    return 0;
}
