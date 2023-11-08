/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:15:23 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/07 22:41:12 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int requiredGradeSign, int requiredGradeExec): _name(name), _signed(false), _requiredGradeSign(requiredGradeSign), _requiredGradeExec(requiredGradeExec)
{
	//std::cout << "Form constructor with params called" << std::endl;
	if(requiredGradeSign < 1 || requiredGradeExec < 1)
		throw(Form::GradeTooHighException());
	if(requiredGradeSign > 150 || requiredGradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src) :_name(src._name), _signed(src._signed), _requiredGradeSign(src._requiredGradeSign), _requiredGradeExec(src._requiredGradeExec)
{
	//std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
	//std::cout << "Buro destructor called" << std::endl;
}

Form& Form::operator=(const Form& src) {
	if (this != &src) {
		this->_signed = src._signed;
	}
	return *this;
}

std::string Form::getName() const {
    return this->_name;
}

int Form::getGradeSign() {
    return this->_requiredGradeSign;
}

int Form::getGradeExec() {
    return this->_requiredGradeExec;
}

bool Form::isSigned() {
	return this->_signed;
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() > this->_requiredGradeSign)
		throw (Form::GradeTooHighException());
	if (this->_signed) {
		std::cout << getName() << ": form is already signed" << std::endl;
		throw (Form::FormAlreadySignedException());
		return;
	}
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, Form& src) {
	os << src.getName() << ", form" << std::endl;
	os << "Required grade to sign: " << src.getGradeSign() << std::endl;
	os << "Required grade to execute: " << src.getGradeExec() << std::endl;
	os << (src.isSigned() ? "Signed" : "Not signed");
	return os;
}
