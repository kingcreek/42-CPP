/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:54:38 by imurugar          #+#    #+#             */
/*   Updated: 2023/04/24 11:01:16 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{

public:
	Zombie( std::string name );
	~Zombie();

	void announce( void );
	Zombie* newZombie( std::string name );
	void randomChump( std::string name );

private:
	std::string name;
};

#endif // ZOMBIE_HPP