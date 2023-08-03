/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:44:25 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/02 16:46:47 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Header-protection
#pragma once

// Includes
#include "ClapTrap.hpp"

// classes

class ScavTrap: public ClapTrap
{
	private:
		bool _guarding_gate;
	public:
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);

		virtual ~ScavTrap();

		ScavTrap &operator=(const ScavTrap &src);

		void attack(const std::string &target);
		void guardGate(void);

};