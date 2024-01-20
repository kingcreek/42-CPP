/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/29 18:23:36 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

/*
class Person {
public:
    int _age;

    Person() : _age(0) {
		std::cout << "Person constructor called" << std::endl;
	}
    Person(int age) : _age(age) {}
};
*/

void try_access(Array<int> arr, int position, std::string str)
{
	try
	{
		std::cout << str << std::endl;
		std::cout << arr[position] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(int, char**)
{
	//Array<Person> pers(10);

	std::cout << "======================" << std::endl;
	std::cout << "=== INVALID ACCESS ===" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << std::endl;
	
	Array<int>empty;
	try_access(empty, 0, "Try access empty array:");
	
	Array<int>small(5);
	try_access(small, 10, "Try invalid access in array:");
	try_access(small, -42, "Try invalid access in array:");
	

	std::cout << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "=== CORRECT ACCESS ===" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << std::endl;
	
	Array<int>arr(10);
	for(int i = 0; i < 10; i++)
	{
		arr[i] = (i + 1) * 10;
	}
	try_access(arr, 6, "Try access correct position:");
	

	std::cout << std::endl;
	std::cout << "========================" << std::endl;
	std::cout << "=== COPY CONSTRUCTOR ===" << std::endl;
	std::cout << "========================" << std::endl;
	std::cout << std::endl;
	
	Array<int>copy(arr);
	
	copy[0] = 42;
	std::cout << "New copy have " << copy[0] << " in position 0" << std::endl;
	std::cout << "Original array have " << arr[0] << " in position 0" << std::endl;

	std::cout << "Copy:" << std::endl;
	for (size_t i = 0; i < copy.size(); i++) std::cout << copy[i] << std::endl;
	std::cout << "Original:" << std::endl;
	for (size_t i = 0; i < arr.size(); i++) std::cout << arr[i] << std::endl;
	
	std::cout << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << "=== OPERATOR (=) ===" << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << std::endl;
	
	copy = arr;
	
	copy[1] = 42;
	std::cout << "New copy have " << copy[1] << " in position 1" << std::endl;
	std::cout << "Original array have " << arr[1] << " in position 1" << std::endl;

	std::cout << "Copy:" << std::endl;
	for (size_t i = 0; i < copy.size(); i++) std::cout << copy[i] << std::endl;
	std::cout << "Original:" << std::endl;
	for (size_t i = 0; i < arr.size(); i++) std::cout << arr[i] << std::endl;


	std::cout << std::endl;
	std::cout << "=================" << std::endl;
	std::cout << "=== WITH CHAR ===" << std::endl;
	std::cout << "=================" << std::endl;
	std::cout << std::endl;
	Array<char> charray(5);
	for (size_t i = 0; i < charray.size(); i++) charray[i] = 'a' + i;

	std::cout << "Char array:" << std::endl;
	for (size_t i = 0; i < charray.size(); i++) std::cout << charray[i] << std::endl;
	
	//Not compile (can read but not write)
	//const Array<char> tmp(charray);
	//std::cout << tmp[0] << std::endl;
	//tmp[0] = 'a';

    return 0;
}
