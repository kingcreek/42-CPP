/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:26:54 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/15 18:23:55 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		
	public:
		Bureaucrat(const std::string& name, int grade);
    	Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();
		
		Bureaucrat& operator=(const Bureaucrat& src);

		// Getters
		const std::string 	getName() const;
		int 				getGrade() const;

		// Grade modifiers
		void				incrementGrade();
		void				decrementGrade();

		// AForm functions
		void			signForm(AForm& src);
		void			executeForm(AForm const& form);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

// Ostream
std::ostream&   operator<<(std::ostream& o, Bureaucrat& src);

#endif
