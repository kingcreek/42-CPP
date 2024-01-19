/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:17:35 by imurugar          #+#    #+#             */
/*   Updated: 2024/01/02 00:10:33 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

class PmergeMe
{

private:
	//Containers used
	std::vector<unsigned int> _vector;
	std::deque<unsigned int> _deque;

	//helper functions
	void validateArgument(std::string arg);
	int calculateThreshold(int size);

	// short template functions (defined in .cpp)
	template <typename Container>
	void merge(Container &arr, int left, int mid, int right);

	template <typename Container>
	void insertionSort(Container &arr, int left, int right);

	template <typename Container>
	void mergeInsertSort(Container &arr, int left, int right);

	//display template function
	template <typename T>
	void display(const T &container)
	{
		typename T::const_iterator it;
		for (it = container.begin(); it != container.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	//helper template functions
	template <typename Container>
	bool isSorted(const Container &arr)
	{
		typename Container::const_iterator it = arr.begin();
		while (it != arr.end() - 1)
		{
			if (*it > *(it + 1))
				return false;
			++it;
		}
		return true;
	}

public:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	~PmergeMe();

	void parseArguments(const char *argv[]);
	void performShort();
};

#endif
