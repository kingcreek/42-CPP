/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:53:15 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/13 14:03:30 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* zombiz = new Zombie[N];
    
    for (int i = 0; i < N; i++) {
        std::stringstream ss;
        ss << name << " " << i;
        zombiz[i].setName(ss.str());
    }
    
    return zombiz;
}