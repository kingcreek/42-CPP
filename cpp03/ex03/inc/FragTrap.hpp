/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:34:13 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/08 10:34:21 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const & rhs);
		FragTrap & operator=(FragTrap const & rhs);
		~FragTrap();
		void highFivesGuys(void);
};

#endif
