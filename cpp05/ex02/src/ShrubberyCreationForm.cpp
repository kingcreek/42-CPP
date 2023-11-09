/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:08:54 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/09 14:47:13 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137) {
	this->setTarget(target);
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy)
: AForm(to_copy.getName(), to_copy.getGradeSign(), to_copy.getGradeExec()) {
	this->setTarget(to_copy.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src) {
		this->setSign(src.isSigned());
		this->setTarget(src.getTarget());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{std::cout << "ShrubberyCreationForm destructor called" << std::endl;}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw Bureaucrat::GradeTooLowException();
	else if (this->isSigned() == false)
		std::cerr << "ShrubberyCreationForm couldn't be executed by " << executor.getName() << " because it wasn't signed!" << std::endl;
	else
	{
		std::ofstream out;

		out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);

		out << "\n"
			<< "─────☆─────" << "\n"
			<< "─────▓˛˚────" << "\n"
			<< "────▓˛˚▓˛˚───" << "\n"
			<< "───▓˛˚▓˛ ▓*──" << "\n"
			<< "──▓˛˚▓˛▓˛*▓˛˚─" << "\n"
			<< "─▓˛▓˚▓˛▓*▓˛▓˛˚" << "\n"
			<< "─────██────" << "\n"
			<< "███████████" << std::endl;
		}
}
