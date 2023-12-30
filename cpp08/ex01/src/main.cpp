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

	std::cout << "====== ERROR HANDLING ======" << std::endl;
	Span f = Span(1);
	f.addNumber(1);
	std::cout << "Create a span with 1 number, try to add another and try to get its spans" << std::endl;
	try {
		f.addNumber(1);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << f.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << f.shortestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "====== FUNCTIONALITY ======" << std::endl;
	Span k(4);

	k.addNumber(1);
	k.addNumber(1);
	k.addNumber(2);

	std::cout << "Longest span: " << k.longestSpan() << std::endl;
	std::cout << "Shortest span: " << k.shortestSpan() << std::endl;

	std::cout << "Add -42" << std::endl;

	k.addNumber(-42);

	std::cout << "Longest span: " << k.longestSpan() << std::endl;
	std::cout << "Shortest span: " << k.shortestSpan() << std::endl;

	std::cout << "Add 20.000 numbers, from 0 to 19.999, incrementing 5" << std::endl;
	Span m(20000);
	std::vector<int> tmp;
	for (int i = 0; i < 20000; i += 5)
		tmp.push_back(i);
	m.fill(tmp.begin(), tmp.end());
	std::cout << "Longest span: " << m.longestSpan() << std::endl;
	std::cout << "Shortest span: " << m.shortestSpan() << std::endl;

	return 0;
}
