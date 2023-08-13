/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:05:03 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/13 20:34:46 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( int argc, char **argv ) {

    if (argc != 2)
        return (std::cout << "Entrada inválida 😔, referencia: " << argv[0] << " <DEBUG, INFO, WARNING, ERROR>\n" << std::flush, 1);
    std::string input = argv[1];
    Harl        harl;

    harl.complain(input);

    return 0;
}