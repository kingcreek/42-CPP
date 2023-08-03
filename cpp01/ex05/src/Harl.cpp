/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:00:40 by imurugar          #+#    #+#             */
/*   Updated: 2023/07/31 11:56:16 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug( void )
{
	std::cout << "🤖  I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do! 🤖" << std::endl;
}

void Harl::info( void )
{
	std::cout << "⏺️  I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more! ⏺️" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "⚠️  I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month. ⚠️" << std::endl;
}

void Harl::error( void )
{
	std::cout << "❌  This is unacceptable! I want to speak to the manager now. ❌" << std::endl;
}

void Harl::complain( std::string level )
{
	
	void (Harl::*logCatLevels[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	for(int i = 0; i < 4; i++)
	{
		if(level == levels[i])
		{
			(this->*logCatLevels[i])();
			return;
		}
	}
	if(level != "EXIT")
		std::cerr << "El imput no está en la lista 🥺" << std::endl;
}