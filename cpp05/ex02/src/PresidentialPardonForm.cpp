/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:50:16 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/09 14:47:38 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5) {
	this->setTarget(target);
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExec()) {
	this->setTarget(copy.getTarget());
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	#ifdef LOGS
		cout << "[PresidentialPardonForm] Destructor called" << endl;
	#endif
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &assign) {
	if (this == &assign)
		return *this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{std::cout << "PresidentialPardonForm destructor called" << std::endl;}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw Bureaucrat::GradeTooLowException();
	else if (this->isSigned() == false)
		std::cerr << "PresidentialPardonForm couldn't be executed by " << executor.getName() << " because it wasn't signed!" << std::endl;
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
