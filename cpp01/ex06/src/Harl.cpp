/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:00:40 by imurugar          #+#    #+#             */
/*   Updated: 2023/09/05 15:23:37 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "🤖  I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do! 🤖" << std::endl;
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "⏺️  I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more! ⏺️" << std::endl;
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "⚠️  I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month. ⚠️" << std::endl;
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "❌  This is unacceptable! I want to speak to the manager now. ❌" << std::endl;
	std::cout << std::endl;
}

void Harl::complain( std::string level )
{
	int i = 0;
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	for(i = 0; i < 4; i++)
		if(level == levels[i])
			break;
			
	switch (i)
    {
    	case    0: 
        	this->debug();
			// fallthrough
    	case    1: 
        	this->info();
			// fallthrough
    	case    2: 
        	this->warning();
			// fallthrough
    	case    3: 
        	this->error();
        	break ;
    	default:
        	std::cout << "[ 🥺 Harl have several problems to understand this command 🥺 ]" << std::endl;
	}
}
