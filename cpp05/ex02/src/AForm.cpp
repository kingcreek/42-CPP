/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:15:23 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/07 23:43:59 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int requiredGradeSign, int requiredGradeExec): _name(name), _signed(false), _requiredGradeSign(requiredGradeSign), _requiredGradeExec(requiredGradeExec)
{
	//std::cout << "AForm constructor with params called" << std::endl;
	if(requiredGradeSign < 1 || requiredGradeExec < 1)
		throw(AForm::GradeTooHighException());
	if(requiredGradeSign > 150 || requiredGradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) :_name(src._name), _signed(src._signed), _requiredGradeSign(src._requiredGradeSign), _requiredGradeExec(src._requiredGradeExec)
{
	//std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm() {
	//std::cout << "Buro destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& src) {
	if (this != &src) {
		this->_signed = src._signed;
	}
	return *this;
}

std::string AForm::getName() const {
    return this->_name;
}

int AForm::getGradeSign() {
    return this->_requiredGradeSign;
}

int AForm::getGradeExec() {
    return this->_requiredGradeExec;
}

bool AForm::isSigned() {
	return this->_signed;
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() > this->_requiredGradeSign)
		throw (AForm::GradeTooHighException());
	if (this->_signed) {
		std::cout << getName() << ": form is already signed" << std::endl;
		throw (AForm::FormAlreadySignedException());
		return;
	}
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, AForm& src) {
	os << src.getName() << ", form" << std::endl;
	os << "Required grade to sign: " << src.getGradeSign() << std::endl;
	os << "Required grade to execute: " << src.getGradeExec() << std::endl;
	os << (src.isSigned() ? "Signed" : "Not signed");
	return os;
}
