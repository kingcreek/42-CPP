/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2024/01/01 09:46:10 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "RPN.hpp"

static int errUsage()
{
	std::cerr << "Error: invalid arguments" << std::endl;
	std::cerr << "Usage: ./RPN <values>" << std::endl;
	return EXIT_FAILURE;
}

// Online calculator for test
// https://paodayag.dev/reverse-polish-notation-js-parser/
int main(int argc, char *argv[])
{

	if (argc != 2)
		return errUsage();

	RPN rpn = RPN();

	try
	{
		rpn.processExpression(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
