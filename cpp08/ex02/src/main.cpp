/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/30 19:41:57 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	// Only to show stack have not iterator
	/*
	std::stack<int> mstackss;
	for (std::stack<int>::iterator it = mstackss.begin(); it != mstackss.end(); ++it) {
        std::cout << *it << std::endl;
    }
	*/

	std::cout << "=================" << std::endl;
	std::cout << "==== Subject ====" << std::endl;
	std::cout << "=================" << std::endl;
	MutantStack<int> mstack;
	std::cout << "Address of mstack: " << &mstack << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);
	std::cout << std::endl;

	std::cout << "========================" << std::endl;
	std::cout << "==== Same with list ====" << std::endl;
	std::cout << "========================" << std::endl;

	std::list<int> lstack;
	std::cout << "Address of lstack: " << &lstack << std::endl;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	
	lstack.push_back(0);
	std::list<int>::iterator iit = lstack.begin();
	std::list<int>::iterator iite = lstack.end();
	++iit;
	--iite;
	while (iit != iite)
	{
		std::cout << *iit << std::endl;
		++iit;
	}
	std::list<int> ss(lstack);
	std::cout << std::endl;

	std::cout << "======================" << std::endl;
	std::cout << "==== Rev iterator ====" << std::endl;
	std::cout << "======================" << std::endl;
	
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }
	std::cout << std::endl;

	std::cout << "================================" << std::endl;
	std::cout << "==== Rev iterator with List ====" << std::endl;
	std::cout << "================================" << std::endl;
	for (std::list<int>::reverse_iterator rit = lstack.rbegin(); rit != lstack.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }
	std::cout << std::endl;

	std::cout << "======================" << std::endl;
	std::cout << "==== Operator (=) ====" << std::endl;
	std::cout << "======================" << std::endl;

	MutantStack<int> mstack2 = mstack;
	std::cout << "Address of mstack: " << &mstack << std::endl;
	std::cout << "Address of mstack2: " << &mstack2 << std::endl;

	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
        std::cout << *it << std::endl;
    }
	std::cout << std::endl;
	
	std::cout << "==============" << std::endl;
	std::cout << "==== Copy ====" << std::endl;
	std::cout << "==============" << std::endl;

	MutantStack<int> mstack3(mstack);
	std::cout << "Address of mstack3: " << &mstack << std::endl;
	std::cout << "Address of mstack3: " << &mstack3 << std::endl;
	for (MutantStack<int>::iterator it = mstack3.begin(); it != mstack3.end(); ++it) {
        std::cout << *it << std::endl;
    }

	return (0);
}
