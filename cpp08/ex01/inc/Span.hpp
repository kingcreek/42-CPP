/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:27:06 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/30 03:26:49 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _vector;

public:
	Span();
	Span(unsigned int);
	Span(const Span &);
	~Span();
	Span &operator=(Span const &);

	void addNumber(int nbr);
	unsigned int longestSpan();
	unsigned int shortestSpan();
	//void fill(void);
	void fill(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif
