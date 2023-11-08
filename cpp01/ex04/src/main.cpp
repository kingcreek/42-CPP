/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:56:27 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/14 14:55:18 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cout << "Entrada inválida 😔, referencia: " << argv[0] << " <archivo> <texto a reemplazar> <texto nuevo>" << std::endl;
		return EXIT_FAILURE;
	}
	Replace replace(argv[1]);
	replace.search_and_replace(argv[2], argv[3]);
	return EXIT_SUCCESS;
}
