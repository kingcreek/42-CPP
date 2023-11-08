/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:05:03 by imurugar          #+#    #+#             */
/*   Updated: 2023/09/05 15:19:34 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string input;
    Harl        harl;

    do
    {
        std::cout << "Enter a level: DEBUG, INFO, WARNING or ERROR. Para salir, EXIT" << std::endl;
        std::cin >> input;
		if (std::cin.eof())
            break;
        harl.complain(input);
    } while (input.compare("EXIT"));
	return 0;
}
