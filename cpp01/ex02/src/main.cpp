/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:05:28 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/14 14:54:52 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

	{
    	// Imprimir direcciones de memoria
    	std::cout << "Dirección de memoria de la variable str: " << &str << std::endl;
    	std::cout << "Dirección de memoria contenida en stringPTR: " << stringPTR << std::endl;
    	std::cout << "Dirección de memoria contenida en stringREF: " << &stringREF << std::endl;
	}

	{
    	// Imprimir valores de la cadena
    	std::cout << "Valor de la variable str: " << str << std::endl;
    	std::cout << "Valor apuntado por stringPTR: " << *stringPTR << std::endl;
    	std::cout << "Valor apuntado por stringREF: " << stringREF << std::endl;
	}
	
    return 0;
}
