/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:08:54 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/15 19:00:01 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137) {
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy)
: AForm(to_copy.getName(), to_copy.getGradeSign(), to_copy.getGradeExec()) {
	this->setTarget(to_copy.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src) {
		this->setSign(src.isSigned());
		this->setTarget(src.getTarget());
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else if (this->isSigned() == false)
		throw FormNotSignedException();
	
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
		<< "█████████████" << std::endl;

	out.close();
}
