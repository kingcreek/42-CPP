/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/27 18:49:46 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "========================" << std::endl;
	std::cout << "=======EXCEPTIONS=======" << std::endl;
	std::cout << "========================" << std::endl;
	{
		// Increase too high constructor
		try
		{
			Bureaucrat bureaucrat("Bureaucrat-1", 0);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Increase too low constructor
		try
		{
			Bureaucrat bureaucrat2("Bureaucrat-2", 160);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		// Increase too high 
		try
		{
			Bureaucrat bureaucrat2("Bureaucrat-3", 5);
			for (int i = 0; i < 20; i++)
			{
				std::cout << bureaucrat2 << std::endl;
				bureaucrat2.incrementGrade();
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		// Decrease too low 
		try
		{
			Bureaucrat bureaucrat2("Bureaucrat-4", 145);
			for (int i = 0; i < 20; i++)
			{
				std::cout << bureaucrat2 << std::endl;
				bureaucrat2.decrementGrade();
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
