/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:49:46 by imurugar          #+#    #+#             */
/*   Updated: 2023/09/19 18:48:56 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 5

int main( void ) {
    Zombie *zombiz = zombieHorde(N, "zombi");

    for (size_t i = 0; i < N; i++) {
        zombiz[i].announce();
    }
	
    delete [] zombiz;
    return 0;
}

char **c = malloc(5 * szeof(char*)) 

free(c)
