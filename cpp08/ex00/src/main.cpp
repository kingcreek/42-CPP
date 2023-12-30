/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/29 19:11:07 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int main(void)
{
	std::cout << "============" << std::endl;
	std::cout << "=== LIST ===" << std::endl;
	std::cout << "============" << std::endl;
	std::cout << std::endl;

	std::list<int> lst;
	for (int i = 1; i <= 10; i++)
		lst.push_back(i);

	for (int o = 7; o <= 14; o++)
	{
		try
		{
			std::cout << "Find value: " << o << ":" << (*easyfind(lst, o)) << std::endl;
		}
		catch (const std::exception &ex)
		{
			std::cerr << "Key not found: " << ex.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "==============" << std::endl;
	std::cout << "=== VECTOR ===" << std::endl;
	std::cout << "==============" << std::endl;
	std::cout << std::endl;

	std::vector<int> vect;
	for (int i = 1; i <= 10; i++)
		vect.push_back(i);

	for (int o = 7; o <= 14; o++)
	{
		try
		{
			std::cout << "Find value: " << o << ":" << (*easyfind(vect, o)) << std::endl;
		}
		catch (const std::exception &ex)
		{
			std::cerr << "Key not found: " << ex.what() << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "=============" << std::endl;
	std::cout << "=== DEQUE ===" << std::endl;
	std::cout << "=============" << std::endl;
	std::cout << std::endl;

	std::deque<int> mydeque;
	for (int i = 1; i <= 10; i++)
		mydeque.push_back(i);

	for (int o = 7; o <= 14; o++)
	{
		try
		{
			std::cout << "Find value: " << o << ":" << (*easyfind(mydeque, o)) << std::endl;
		}
		catch (const std::exception &ex)
		{
			std::cerr << "Key not found: " << ex.what() << std::endl;
		}
	}

	return 0;
}
