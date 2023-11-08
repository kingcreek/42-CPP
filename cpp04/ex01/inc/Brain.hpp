/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:09:40 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/17 16:43:53 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
		
	public:
		Brain(void);
		Brain(const Brain& cpy);
		~Brain();
		Brain& operator=(const Brain& cpy);
	
};

#endif
