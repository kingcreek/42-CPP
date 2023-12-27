/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:08:38 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/27 18:40:35 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("RobotomyRequestForm", 72, 45) {
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy)
: AForm(to_copy.getName(), to_copy.getGradeSign(), to_copy.getGradeExec()) {
	this->setTarget(to_copy.getTarget());
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &assign) {
	if (this == &assign)
		return *this;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else if (this->isSigned() == false)
		throw FormNotSignedException();
	
	std::srand(std::time(NULL));
	std::cout << "(Loud drill noises) " << std::endl;
	if (random() % 2 == 0)
		std::cout << this->getTarget() << " successfully robotomized." << std::endl;
	else
		std::cout << this->getTarget() << " failed when trying to robotimize." << std::endl;
}
