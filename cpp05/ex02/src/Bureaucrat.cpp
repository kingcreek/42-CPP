/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:26:57 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/15 18:32:48 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	//std::cout << "Bureaucrat constructor with params called" << std::endl;
	if(grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) :_name(src._name), _grade(src._grade)
{
	//std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	//std::cout << "Buro destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src) {
		this->_grade = src._grade;
	}
	return *this;
}

const std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void    Bureaucrat::incrementGrade() {
    if ( this->_grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void    Bureaucrat::decrementGrade() {
    if ( this->_grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

std::ostream& operator<<( std::ostream& o, Bureaucrat& src ) {
    o << src.getName() << ", bureaucrat grade " << src.getGrade();
    return o;
}

void Bureaucrat::signForm(AForm& src) {
	try {
		src.beSigned(*this);
	}
	catch (AForm::GradeTooHighException& e) {
		std::cout << this->getName() << " couldn't sign form " << src.getName()
			<< " because " << e.what() << std::endl;
		return ;
	}
	catch (AForm::FormAlreadySignedException& e) {
		std::cout << this->getName() << " couldn't sign form " << src.getName()
			<< " because " << e.what() << std::endl;
		return;	
	}
	std::cout << this->getName() << " signed " << src.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
	}
	catch (AForm::GradeTooLowException& e) {
		std::cout << this->getName() << " couldnt execute form " << form.getName();
		std::cout << " (reason: " << e.what() << ")" << std::endl;
		return;
	}
	catch (AForm::FormNotSignedException& e) {
		std::cout << this->getName() << " couldn't sign form " << form.getName();
		std::cout << " (reason: " << e.what() << ")" << std::endl;
		return;
	}
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException: Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException: Grade too low";
}
