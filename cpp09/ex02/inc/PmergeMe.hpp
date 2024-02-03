/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:17:35 by imurugar          #+#    #+#             */
/*   Updated: 2024/02/03 19:41:43 by imurugar         ###   ########.fr       */
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
	// Containers used
	std::vector<unsigned int> _vector;
	std::deque<unsigned int> _deque;

	// helper functions
	void validateArgument(std::string arg);
	int calculateThreshold(int size);

	template <typename T>
	void display(const T &container)
	{
		typename T::const_iterator it;
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
