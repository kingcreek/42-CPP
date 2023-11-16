/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:39:59 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/15 18:25:21 by imurugar         ###   ########.fr       */
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
		std::string	_target;
		
	public:
		AForm(const std::string& name, int requiredGradeSign, int requiredGradeExec);
    	AForm(const AForm& src);
		virtual ~AForm();
		AForm& operator=(const AForm& src);

		// Getters
		const std::string	getName() const;
		bool				isSigned() const;
		int 				getGradeSign() const;
		int 				getGradeExec() const;
		std::string			getTarget(void) const;

		// Functions
		void			beSigned(Bureaucrat&);
		virtual void	execute(Bureaucrat const & executor) const = 0;
		void			setTarget(std::string target);
		void			setSign(bool);

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
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

// Ostream
std::ostream&   operator<<(std::ostream& o, AForm& src);

#endif
