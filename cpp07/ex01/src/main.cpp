/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/28 22:15:01 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::cout << "=========" << std::endl;
	std::cout << "INT ARRAY" << std::endl;
	std::cout << "=========" << std::endl;
	
	int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original array: ";
    iter(intArray, intArrayLength, &print);
	//iter(intArray, intArrayLength, print<int>);
    std::cout << std::endl;

    iter(intArray, intArrayLength, &increment);
	//iter(intArray, intArrayLength, increment<int>);
    std::cout << "After increment: ";
    iter(intArray, intArrayLength, &print);
	//iter(intArray, intArrayLength, print<int>);
    std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "============" << std::endl;
	std::cout << "DOUBLE ARRAY" << std::endl;
	std::cout << "============" << std::endl;
	
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Original array: ";
    iter(doubleArray, doubleArrayLength, &print);
    std::cout << std::endl;

    iter(doubleArray, doubleArrayLength, &increment);

    std::cout << "After increment: ";
    iter(doubleArray, doubleArrayLength, &print);
    std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "==========" << std::endl;
	std::cout << "CHAR ARRAY" << std::endl;
	std::cout << "==========" << std::endl;
	
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Original array: ";
    iter(charArray, charArrayLength, &print);
    std::cout << std::endl;

    iter(charArray, charArrayLength, &increment);

    std::cout << "After increment: ";
    iter(charArray, charArrayLength, &print);
    std::cout << std::endl;
	
	return 0;
}
