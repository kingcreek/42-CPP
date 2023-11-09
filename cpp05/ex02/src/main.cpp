/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:04 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/09 14:49:15 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main (void)
{

	Bureaucrat hermano("Hermano", 150);

	Bureaucrat ebil("Ebil", 1);
	std::cout << std::endl;

	std::cout << std::endl;
	ShrubberyCreationForm scf("Ebil");
	PresidentialPardonForm ppf("Ebil");
	RobotomyRequestForm rrf("Ebil");
	std::cout << std::endl;

	ebil.executeForm(scf);
	scf.beSigned(ebil);
	ebil.executeForm(scf);

	std::cout << std::endl;

	ebil.executeForm(ppf);
	ppf.beSigned(ebil);
	ebil.executeForm(ppf);

	std::cout << std::endl;

	ebil.executeForm(rrf);
	rrf.beSigned(ebil);
	ebil.executeForm(rrf);

	std::cout << std::endl;

	try {
		hermano.executeForm(scf);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
}
