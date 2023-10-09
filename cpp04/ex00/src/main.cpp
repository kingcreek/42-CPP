/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:42:39 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/09 11:04:01 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>

int main( void )
{
    std::cout << "--------------- Animal ---------------" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	
	std::cout << "Animal Type: " << meta->getType() << std::endl;
    std::cout << "Dog type: " << j->getType() << std::endl;
    std::cout << "Cat Type: " << i->getType() << std::endl;
    i->makeSound();
	j->makeSound();
    meta->makeSound();

    delete  meta;
    delete  j;
    delete  i;

    std::cout << std::endl << "------------- Wrong Animal -------------" << std::endl;

    const WrongAnimal *wrong = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();
	
    std::cout << "Wrong Type: " << wrong->getType() << " " << std::endl;
    std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
    wrong->makeSound();
    wrongCat->makeSound();

    delete  wrong;
    delete  wrongCat;

    return 0;
}
