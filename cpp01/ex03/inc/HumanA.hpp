/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:13:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/14 14:54:56 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		
		void attack(void) const;
		Weapon& getWeapon(void) const;
	
};

#endif
