/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:51:36 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/27 18:51:03 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCF_HPP
# define SCF_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
		
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

		void execute(Bureaucrat const & executor) const;
};

#endif
