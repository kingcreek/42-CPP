/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:11:11 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/10 23:37:01 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[]){
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string message;

	for (int i = 1; i < argc; i++)
		message += argv[i];
	for (std::string::iterator it = message.begin(); it != message.end(); it++)
		*it = std::toupper(*it);
	std::cout << message << std::endl;
	return (0);
}
