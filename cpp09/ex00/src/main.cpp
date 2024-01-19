/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2024/01/01 09:46:21 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "BitcoinExchange.hpp"

static int errUsage()
{
	std::cerr << "Error: invalid arguments" << std::endl;
	std::cerr << "Usage: ./btc <path_to_input.csv>" << std::endl;
	return EXIT_FAILURE;
}

int main(int argc, char *argv[])
{

	if (argc != 2)
		return errUsage();

	BitcoinExchange btc = BitcoinExchange();
	std::string file = argv[1];
	btc.process(file);
}
