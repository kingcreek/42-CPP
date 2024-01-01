/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:18:39 by imurugar          #+#    #+#             */
/*   Updated: 2024/01/02 00:06:39 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_vector = src._vector;
		this->_deque = src._deque;
	}
	return *this;
}

int PmergeMe::calculateThreshold(int threshold)
{
    return (std::max(10, threshold / 10));
}

template <typename Container>
void PmergeMe::merge(Container &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Container leftSubvec(arr.begin() + left, arr.begin() + left + n1);
    Container rightSubvec(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftSubvec[i] <= rightSubvec[j]) {
            arr[k] = leftSubvec[i];
            i++;
        } else {
            arr[k] = rightSubvec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftSubvec[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightSubvec[j];
        j++;
        k++;
    }
}

template <typename Container>
void PmergeMe::insertionSort(Container &arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        typename Container::value_type key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container &arr, int left, int right) {
    if (left < right) {
        if (right - left + 1 <= calculateThreshold(right - left + 1)) {
            insertionSort(arr, left, right);
        } else {
            int mid = left + (right - left) / 2;
            mergeInsertSort(arr, left, mid);
            mergeInsertSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}

void PmergeMe::validateArgument(std::string arg)
{
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (!std::isdigit(arg[i]))
			throw std::runtime_error("Invalid argument => " + arg);
	}
	long res = std::atol(arg.c_str());
	if (res > INT_MAX || res < 0)
		throw std::runtime_error("The number must be a positive INT => " + arg);
}

void PmergeMe::parseArguments(const char *argv[])
{
	for (int i(0); argv[i]; i++)
	{
		validateArgument(argv[i]);
		this->_vector.push_back(std::atoi(argv[i]));
		this->_deque.push_back(std::atoi(argv[i]));
	}
}

void PmergeMe::performShort()
{
	std::cout << "Before: ";
    display(this->_deque);

	clock_t start1 = clock();
    mergeInsertSort(this->_deque, 0, this->_deque.size() - 1);
	if (!isSorted(this->_deque))
        std::cout << "Failed to sort deque!" << std::endl;
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / (CLOCKS_PER_SEC / 1000.0);

    clock_t start2 = clock();
    mergeInsertSort(this->_vector, 0, this->_vector.size() - 1);
	if (!isSorted(this->_vector))
        std::cout << "Failed to sort vector!" << std::endl;
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / (CLOCKS_PER_SEC / 1000.0);

	std::cout << "After: ";
    display(this->_deque);
    std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::list container: " << time2 << " us" << std::endl;
}
