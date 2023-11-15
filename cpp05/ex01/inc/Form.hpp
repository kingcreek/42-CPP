/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:39:59 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/15 18:20:29 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_requiredGradeSign;
		const int			_requiredGradeExec;
		
	public:
		Form(const std::string& name, int requiredGradeSign, int requiredGradeExec);
    	Form(const Form& src);
		~Form();
		Form& operator=(const Form& src);

		// Getters
		std::string	getName() const;
		bool		isSigned();
		int 		getGradeSign();
		int 		getGradeExec();

		// Functions
		void		beSigned(Bureaucrat&);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

// Ostream
std::ostream&   operator<<(std::ostream& o, Form& src);

#endif
