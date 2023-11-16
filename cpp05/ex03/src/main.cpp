/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/16 07:31:10 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    Intern i;

	AForm* f = i.makeForm("robotomy request", "carlos");
	std::cout << *f << std::endl;
	AForm* f2 = i.makeForm("shrubbery creation", "carlos");
	std::cout << *f2 << std::endl;
	AForm* f3 = i.makeForm("presidential pardon", "carlos");
	std::cout << *f3 << std::endl;

	delete f;
	delete f2;
	delete f3;

	std::cout << "Now lets create invalid stuff" << std::endl;
	AForm* f4 = i.makeForm("juan", "carlos");
	(void) f4;
}