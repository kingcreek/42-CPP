/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:54:05 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/13 16:53:55 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <sstream>

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