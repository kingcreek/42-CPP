/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 00:37:31 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/08 10:34:17 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap 
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &original);
		DiamondTrap &operator=(const DiamondTrap &original);
		~DiamondTrap(void);

		using ScavTrap::attack;
		void whoAmI(void);

	private:
		std::string _name;
};

#endif
