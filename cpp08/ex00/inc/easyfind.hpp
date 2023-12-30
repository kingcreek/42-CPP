/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:30:06 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/29 19:09:23 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>


template <typename T>
typename T::iterator easyfind(T& in, int i)
{
	typename T::iterator it = std::find(in.begin(), in.end(), i);
	if(it == in.end())
		throw std::runtime_error("Cannot find element in container");
	return it;
}

#endif
