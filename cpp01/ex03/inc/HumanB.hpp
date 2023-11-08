/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:13:07 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/14 14:54:59 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;
	
	public:
		HumanB(std::string name);
		~HumanB(void);
		
		void	attack(void) const;
		void	setWeapon(Weapon& newWeapon);
	
};

#endif
