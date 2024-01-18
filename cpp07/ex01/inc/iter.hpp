/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:56:30 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/28 21:55:47 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <cstddef>
# include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
	if (!array || !func)
        return ;
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void increment(T& value) {
    value++;
}

template <typename T>
void print(T& value) {
    std::cout << value << " ";
}

#endif
