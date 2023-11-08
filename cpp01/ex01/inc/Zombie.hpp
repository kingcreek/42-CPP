/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:54:05 by imurugar          #+#    #+#             */
/*   Updated: 2023/09/04 10:30:43 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    
private:
    std::string _name;

public:
    Zombie();
    ~Zombie();
    void    announce(void);
    Zombie* newZombie(std::string name);
    void    setName(std::string name);

};

Zombie*    zombieHorde(int N, std::string name);

#endif
