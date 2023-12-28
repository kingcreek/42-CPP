/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:51:12 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/27 18:52:00 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRF_HPP
# define RRF_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
		
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm(void);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

		void execute(Bureaucrat const & executor) const;
};

#endif
