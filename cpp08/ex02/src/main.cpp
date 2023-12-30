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
	// PDF Provided Main
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Main provided by the Sunbject" << std::endl;
	std::cout << "-----------------------------" << std::endl;
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
	// To show that the stack is indeed a stack, we can also use the std::stack
	std::stack<int> s(mstack);

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Testing with a list instead of MutantStack" << std::endl;
	std::cout << "------------------------------------------" << std::endl;

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
	//[...]
	lstack.push_back(0);
	std::list<int>::iterator iit = lstack.begin();
	std::list<int>::iterator iite = lstack.end();
	++it;
	--it;
	while (iit != iite)
	{
		std::cout << *iit << std::endl;
		++iit;
	}
	std::list<int> ss(lstack);
	std::cout << std::endl;

	std::cout << "---------------------------" << std::endl;
	std::cout << "Testing assignment overload" << std::endl;
	std::cout << "---------------------------" << std::endl;

	MutantStack<int> mstack2 = mstack;
	std::cout << "Address of mstack2: " << &mstack2 << std::endl;
	MutantStack<int>::iterator it2 = mstack2.begin();
	MutantStack<int>::iterator ite2 = mstack2.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << "---------------------" << std::endl;
	std::cout << "Testing copy operator" << std::endl;
	std::cout << "---------------------" << std::endl;
	MutantStack<int> mstack3(mstack);
	std::cout << "Address of mstack3: " << &mstack3 << std::endl;
	MutantStack<int>::iterator it3 = mstack3.begin();
	MutantStack<int>::iterator ite3 = mstack3.end();
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}

	return (0);
}
