/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:41:03 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/28 20:54:21 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T &min(const T &a, const T &b) {
	return (a < b) ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b) {
	return (a > b) ? a : b;
}

#endif
