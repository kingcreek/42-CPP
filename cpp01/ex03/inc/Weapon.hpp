/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:13:09 by imurugar          #+#    #+#             */
/*   Updated: 2023/07/31 08:49:52 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{

public:

	Weapon(std::string type);
	~Weapon(void);

	const std::string&	getType(void) const;
	bool				setType(const std::string& newType);

private:
	std::string type;

};

#endif