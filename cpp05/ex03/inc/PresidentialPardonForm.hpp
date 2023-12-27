/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:49:44 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/27 18:19:53 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPF_HPP
# define PPF_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
		
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm(void);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

		void execute(Bureaucrat const & executor) const;
};

#endif
