/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/28 17:49:39 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
	Data data;
	data.character = 'Z';
	data.value = 1337;
	
	std::cout << "Original Data pointer address " << &data << std::endl;
	std::cout << std::endl;
	
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << "Data Value: " << data.value << std::endl;
    std::cout << "Data Character: " << data.character << std::endl;
    std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	
    std::cout << "Deserialized value: " << deserialized << std::endl;
    std::cout << "Data Value: " << deserialized->value << std::endl;
    std::cout << "Data Character: " << deserialized->character << std::endl;
    std::cout << std::endl;

    // Check if the deserialized pointer is equal to the address of the original 'data' object
    if (deserialized == &data)
        std::cout << "Serialization and deserialization worked correctly!\n";
    else
        std::cout << "Serialization and deserialization failed.\n";

    return (0);
}
