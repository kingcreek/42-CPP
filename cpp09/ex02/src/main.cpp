/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2024/01/01 21:40:13 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// based on https://iq.opengenus.org/merge-insertion-sort

static int errUsage()
{
	std::cout << "Error: invalid arguments" << std::endl;
	std::cout << "Usage: ./PmergeMe <N numbers>" << std::endl;
	return EXIT_FAILURE;
}

int main(int argc, const char *argv[])
{

	if (argc < 2)
		return errUsage();
	PmergeMe pmerge = PmergeMe();

	try
	{
		pmerge.parseArguments(++argv);
		pmerge.performShort();
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return EXIT_SUCCESS;
}
