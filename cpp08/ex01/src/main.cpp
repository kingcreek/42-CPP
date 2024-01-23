/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/30 16:36:04 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	std::cout << "====== SUBJECT MAIN ======" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "============================" << std::endl;
	std::cout << "====== ERROR HANDLING ======" << std::endl;
	std::cout << "============================" << std::endl;

	std::cout << "Creating a span with 1 number and adding the number" << std::endl;
	Span f = Span(1);
	f.addNumber(1);

	std::cout << "Trying add another number" << std::endl;
	try {
		f.addNumber(1);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Getting longest span" << std::endl;
	try {
		std::cout << f.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Getting shortest span" << std::endl;
	try {
		std::cout << f.shortestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "==========================" << std::endl;
	std::cout << "====== NORMAL USAGE ======" << std::endl;
	std::cout << "==========================" << std::endl;

	Span k(4);

	k.addNumber(1);
	k.addNumber(1);
	k.addNumber(2);

	std::cout << "Longest: " << k.longestSpan() << std::endl;
	std::cout << "Shortest: " << k.shortestSpan() << std::endl;

	std::cout << "Adding -42" << std::endl;

	k.addNumber(-42);

	std::cout << "Longest: " << k.longestSpan() << std::endl;
	std::cout << "Shortest: " << k.shortestSpan() << std::endl;

	std::cout << "Adding 20000 numbers, init: 0 end 39998 (i * 2)" << std::endl;
	Span m(20000);
	std::vector<int> tmp;
	for (int i = 0; i < 20000; i++)
		tmp.push_back(i * 2);
	m.fill(tmp.begin(), tmp.end());
	std::cout << "Longest span: " << m.longestSpan() << std::endl;
	std::cout << "Shortest span: " << m.shortestSpan() << std::endl;

	return 0;
}
