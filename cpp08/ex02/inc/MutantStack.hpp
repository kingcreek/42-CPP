/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:13:30 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/30 20:04:52 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <list>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const &other) : std::stack<T>(other) {}
		
		//Redundant operator =, stack already have implemented
        MutantStack &operator=(MutantStack const &other)
        {
            if (this != &other)
            {
                std::stack<T>::operator=(other);
            }
            return (*this);
        }
		//Same with destructor
        ~MutantStack() {}

		//
		//Operators ++, -- etc are not need implement because this class extends from stack
		//
		
		
		// https://en.cppreference.com/w/cpp/header/stack
		// this->c, its a reference to protected Container
		// container_type: defined in stack header
		// by default {container_type} it's a subyacent {deque} container inside stack container,
		// then we can acces to iterator of deque and create alias.
		
		// Define an alias 'iterator' for the iterator type of the underlying container
        typedef typename std::stack<T>::container_type::iterator iterator;
		// Define an alias 'reverse_iterator', same as iterator but for reverse
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		// Now with const iterator
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// Iterators
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		// Const iterators
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
