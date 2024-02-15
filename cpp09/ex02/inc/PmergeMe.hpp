/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:17:35 by imurugar          #+#    #+#             */
/*   Updated: 2024/02/15 06:55:26 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
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

	template <typename Container>
	void merge(Container &arr, int left, int mid, int right)
	{
		int n1 = mid - left + 1;
		int n2 = right - mid;

		Container leftSubvec(arr.begin() + left, arr.begin() + left + n1);
		Container rightSubvec(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2);

		int i = 0, j = 0, k = left;

		while (i < n1 && j < n2)
		{
			if (leftSubvec[i] <= rightSubvec[j])
				arr[k++] = leftSubvec[i++];
			else
				arr[k++] = rightSubvec[j++];
		}

		while (i < n1)
			arr[k++] = leftSubvec[i++];

		while (j < n2)
			arr[k++] = rightSubvec[j++];
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
	void insertionSort(Container &arr, int left, int right)
	{
		for (int i = left + 1; i <= right; i++)
		{
			typename Container::value_type key = arr[i];
			int j = i - 1;
			while (j >= left && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
	}

	template <typename Container>
	void mergeInsertSort(Container &arr, int left, int right)
	{
		if (left < right)
		{
			if (right - left + 1 <= calculateThreshold(right - left + 1))
			{
				insertionSort(arr, left, right);
			}
			else
			{
				int mid = left + (right - left) / 2;
				mergeInsertSort(arr, left, mid);
				mergeInsertSort(arr, mid + 1, right);
				merge(arr, left, mid, right);
			}
		}
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
