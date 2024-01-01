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
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

        iterator begin() { return (this->c.begin()); }
        iterator end() { return (this->c.end()); }
        reverse_iterator rbegin() { return (this->c.rbegin()); }
        reverse_iterator rend() { return (this->c.rend()); }
};

/*
#include <stack>
#include <deque>
#include <list>
#include <iostream>

// Forward declaration for iterator
template <typename T, typename Container>
class MutantStackIterator;

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    // Inherit constructors
    explicit MutantStack(const Container& cont = Container()) : std::stack<T, Container>(cont) {}

    // Iterator types
    typedef MutantStackIterator<T, Container> iterator;
    typedef MutantStackIterator<T, Container> const_iterator;

    // Iterators for the underlying container
    iterator begin() { return iterator(this->c.begin()); }
    iterator end() { return iterator(this->c.end()); }

    const_iterator begin() const { return const_iterator(this->c.begin()); }
    const_iterator end() const { return const_iterator(this->c.end()); }
};

// Iterator class
template <typename T, typename Container>
class MutantStackIterator {
private:
    typename Container::iterator iter;

public:
    MutantStackIterator(typename Container::iterator it) : iter(it) {}

    MutantStackIterator& operator++() {
        ++iter;
        return *this;
    }

    MutantStackIterator operator++(int) {
        MutantStackIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    MutantStackIterator& operator--() {
        --iter;
        return *this;
    }

    MutantStackIterator operator--(int) {
        MutantStackIterator tmp = *this;
        --(*this);
        return tmp;
    }

    bool operator==(const MutantStackIterator& rhs) const {
        return iter == rhs.iter;
    }

    bool operator!=(const MutantStackIterator& rhs) const {
        return !(*this == rhs);
    }

    T& operator*() {
        return *iter;
    }
};
*/

#endif
