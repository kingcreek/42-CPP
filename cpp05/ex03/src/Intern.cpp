/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 07:15:52 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/27 18:52:14 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern(void)
{
}

Intern & Intern::operator=(Intern const & src)
{
	if (this != &src)
        *this = src;
	return *this;
}

AForm*   Intern::makeForm(std::string name, std::string target) {

    std::string formNames[] = {
        "robotomy request",
        "presidential request",
        "shrubbery request"
    };
	/*
    AForm*    forms[] = {
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
        new ShrubberyCreationForm(target)
    };
	*/
    
    for (int i(0); i < 3; i++) {
        if (name == formNames[i]) {
			switch(i)
			{
				case 0:
					return new RobotomyRequestForm(target);
				case 1:
					return new PresidentialPardonForm(target);
				case 2:
					return new ShrubberyCreationForm(target);
			}
        }
    }
    std::cout << "Intern cannot create " << name << " form" << std::endl;
    return NULL;
}
