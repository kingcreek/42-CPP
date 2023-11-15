/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:26:57 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/15 18:18:34 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

const std::string Bureaucrat::getName() {
	return this->_name;
}

int Bureaucrat::getGrade() {
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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException: Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException: Grade too low";
}
