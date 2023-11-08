/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:54:38 by imurugar          #+#    #+#             */
/*   Updated: 2023/09/04 10:11:45 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{

public:
	Zombie(std::string name);
	~Zombie();

	void	announce(void);

private:
	std::string name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);
	
#endif
