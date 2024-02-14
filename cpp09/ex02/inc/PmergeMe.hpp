/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:17:35 by imurugar          #+#    #+#             */
/*   Updated: 2024/02/14 08:19:23 by imurugar         ###   ########.fr       */
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
#include <limits>

class PmergeMe
{
	private:
		// Containers used
		std::deque<unsigned int> _deque;
		std::vector<unsigned int> _vector;

		// helper functions
		void validateArgument(std::string arg);
		int calculateThreshold(int size);

		template <typename Container>
		void display(const Container &container)
		{
			typename Container::const_iterator it;
			for (it = container.begin(); it != container.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

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

		/*
			Example:
			array {6 4 2 5 1 0}
			-Take the number N and save it in `key` (start in position 1)
			-We compare all the previous numbers and move them to the next position as long as our number N is greater than said number and no left numbers.
				-Take 4 as `key`
				-Compare with back numbers
					- 6 are bigger than key => true, then set 6 in 1nd position
					- while stop here, because are no left numbers
					- set key (4 in the position we stopped: 0)
			new array {4 6 2 5 1 0}
				-Take 2 as key
				-Compare with back numbers
					- 6 are bigger than key => true, then set 6 in 2nd position
					- 4 are bigger than key => true, then set 4 in 1nd position
					- while stop here, because are no left numbers
					- set key (2 in the position we stopped: 0)
			new array {2 4 6 5 1 0}
				-Take 5 as key
				-Compare with back numbers
					- 6 are bigger than key => true, then set 6 in 3nd position
					- while stop here, because 4 are lower than 5
					- set key (5 in the position we stopped: 2)
			new array {2 4 5 6 1 0}
				...
		*/
		template <typename Container>
		void insertionSort(Container &m)
		{
			unsigned int key;
			typename Container::iterator it;
			typename Container::iterator prev;
			typename Container::iterator j;
			for (it = m.begin(); it != m.end(); ++it)
			{
				key = *it;
				j = it;
				while (j != m.begin())
				{
					prev = j;
					--prev;
					if (*prev > key)
					{
						*j = *prev;
						--j;
					}
					else
						break;
				}
				*j = key;
			}
		}

		template <typename Container>
		void mergeInsertSort(Container &m)
		{
			size_t len = m.size();
			size_t threshold = calculateThreshold(len);

			if (len > threshold)
			{
				typename Container::iterator begin = m.begin();
				typename Container::iterator mid = m.begin();
				std::advance(mid, m.size() / 2);
				typename Container::iterator end = m.end();
				Container left(begin, mid);
				Container right(mid, end);
				if (left.size() > 1)
					mergeInsertSort(left);
				if (right.size() > 1)
					mergeInsertSort(right);
				std::merge(left.begin(), left.end(), right.begin(), right.end(), m.begin());
			}
			else
				insertionSort(m);
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
