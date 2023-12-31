/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:15:23 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/27 18:51:08 by imurugar         ###   ########.fr       */
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

const std::string AForm::getName() const {
    return this->_name;
}

int AForm::getGradeSign() const {
    return this->_requiredGradeSign;
}

int AForm::getGradeExec() const {
    return this->_requiredGradeExec;
}

bool AForm::isSigned() const {
	return this->_signed;
}

std::string AForm::getTarget(void) const {
	return this->_target;
}

void AForm::setTarget(std::string target) {
	this->_target = target;
}

void AForm::setSign(bool sign) {
	this->_signed = sign;
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

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm::GradeTooHighException: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm::GradeTooLowException: Grade too low";
}

const char* AForm::FormAlreadySignedException::what() const throw() {
	return "AForm::AFormAlreadySignedException: Form already signed";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "AForm::FormNotSignedException: Form form not signed";
}
