/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:17:35 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/31 22:29:01 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{

private:
	std::vector<unsigned int> 	_vecor;
	std::deque<unsigned int> 	_deque;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	~PmergeMe();
};

#endif
