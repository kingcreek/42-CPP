/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/07 22:31:46 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "========================" << std::endl;
	std::cout << "=======EXCEPTIONS=======" << std::endl;
	std::cout << "========================" << std::endl;
	{
		// Form too high constructor
		try
		{
			Form form("Form-1", 0, 1);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Form too low constructor
		try
		{
			Form form("Form-1", 151, 1);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "==================" << std::endl;
	std::cout << "=======SIGN=======" << std::endl;
	std::cout << "==================" << std::endl;
	{
		// Form too high to sign
		try
		{
			std::cout << "Next bureaucrat cant't sign:" << std::endl;
			Bureaucrat bureaucrat("Bureaucrat-1", 5);
			std::cout << bureaucrat << std::endl;
			Form form("Form-1", 1, 1);
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Can sign
		try
		{
			std::cout << std::endl;
			std::cout << "Next bureaucrat success sign:" << std::endl;
			Bureaucrat bureaucrat("Bureaucrat-2", 1);
			std::cout << bureaucrat << std::endl;
			Form form("Form-2", 1, 1);
			std::cout << form << std::endl;
			bureaucrat.signForm(form);
			std::cout << form.getName() << ": " << ((form.isSigned() == 1) ? "Signed" : "Not signed") << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		// Try sign multiple times
		try
		{
			std::cout << std::endl;
			Bureaucrat bureaucrat("Bureaucrat-3", 1);
			Form form("Form-3", 100, 100);
			for (int i = 0; i < 5; i++)
				bureaucrat.signForm(form);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
