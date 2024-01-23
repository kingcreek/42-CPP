/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:27:23 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/30 03:33:21 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &src) : _N(src._N), _vector(src._vector) {}

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_N = src._N;
		this->_vector = src._vector;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int nbr)
{
	if (this->_vector.size() == this->_N)
		throw std::runtime_error("Span is full");
	this->_vector.push_back(nbr);
}

unsigned int Span::longestSpan()
{
	if (this->_vector.size() <= 1)
		throw std::runtime_error("No span can be detected");
		
	std::sort(this->_vector.begin(), this->_vector.end());
	return this->_vector.back() - this->_vector.front();
}

unsigned int Span::shortestSpan()
{
	if (this->_vector.size() <= 1)
		throw std::runtime_error("No span can be detected");

	if (this->_vector.size() == 2)
		return this->longestSpan();

	std::sort(this->_vector.begin(), this->_vector.end());
	unsigned int minSpan = this->_vector[1] - this->_vector[0];

	for (size_t i = 1; i < this->_vector.size(); ++i)
	{
		unsigned int span = this->_vector[i] - this->_vector[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((unsigned int) std::distance(begin, end) > this->_N - this->_vector.size())
		throw std::runtime_error("Not all elements fit");
	while (begin != end && _vector.size() < _N)
	{
		_vector.push_back(*begin);
		++begin;
	}
}
