/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:42:11 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/28 23:45:08 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <iostream>
#include <stdexcept>

template <class T>
class Array
{

private:
	T *_arr;
	unsigned int _size;

public:
	Array() : _arr(new T[0]), _size(0)
	{
		if (_arr == NULL)
        	throw std::bad_alloc();
	}

	~Array()
	{ 
		if (this->_arr != NULL)
        	delete[] _arr;
	}

	Array(unsigned int n): _arr(new T[n]), _size(n)
	{
		if (_arr == NULL)
        	throw std::bad_alloc();
		for (unsigned int i = 0; i < n; ++i)
    	{
        	_arr[i] = T();
    	}
	}
	Array(const Array &other): _arr(new T[other._size]), _size(other._size)
	{
		if (_arr == NULL)
        	throw std::bad_alloc();
		for (size_t i = 0; i < _size; i++)
		{
			this->_arr[i] = other._arr[i];
		}
	}
	Array &operator=(const Array &other)
	{
		if (this != &other)
    	{
			delete[] _arr;
			this->_size = other._size;
			this->_arr = new T[_size];
			if (_arr == NULL)
            	throw std::bad_alloc();
			for (size_t i = 0; i < _size; i++)
			{
				this->_arr[i] = other._arr[i];
			}
		}
		return *this;
	};

	T &operator[](int i)
	{
		if (i < 0 || (unsigned int)i >= this->_size)
		{
			throw std::out_of_range("Index out of range");
		}
		return this->_arr[i];
	}

	const T &operator[](int i) const
	{
		if (i < 0 || (unsigned int)i >= this->_size)
		{
			throw std::out_of_range("Index out of range");
		}
		return this->_arr[i];
	}

	unsigned int size() const
	{
		return this->_size;
	}
};

#endif
