/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:49:46 by imurugar          #+#    #+#             */
/*   Updated: 2023/07/29 11:02:32 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 4

int main( void ) {
    Zombie *zombiz = zombieHorde(N, "zombi");

    for (size_t i = 0; i < N; i++) {
        zombiz[i].announce();
    }
	
    delete [] zombiz;
    return 0;
}