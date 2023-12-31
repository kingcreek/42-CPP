/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:26:54 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/15 18:15:56 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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
		const std::string 	getName();
		int 				getGrade();

		// Grade modifiers
		void				incrementGrade();
		void				decrementGrade();

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
