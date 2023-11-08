/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:39:59 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/07 23:49:26 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_requiredGradeSign;
		const int			_requiredGradeExec;
		
	public:
		AForm(const std::string& name, int requiredGradeSign, int requiredGradeExec);
    	AForm(const AForm& src);
		~AForm();
		AForm& operator=(const AForm& src);

		// Getters
		std::string	getName() const;
		bool		isSigned();
		int 		getGradeSign();
		int 		getGradeExec();

		// Functions
		void			beSigned(Bureaucrat&);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "AForm::GradeTooHighException: Grade too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "AForm::GradeTooLowException: Grade too low"; }
		};
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw() { return "AForm::AFormAlreadySignedException: AForm already signed"; }
		};
};

// Ostream
std::ostream&   operator<<(std::ostream& o, AForm& src);

#endif
