/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:51:12 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/08 15:49:51 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRF_HPP
# define RRF_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm(void);
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm(void);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

		void execute(Bureaucrat const & executor) const;
};

#endif