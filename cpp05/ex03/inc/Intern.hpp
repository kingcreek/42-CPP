/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 07:12:12 by imurugar          #+#    #+#             */
/*   Updated: 2023/11/16 07:15:40 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & obj);
		~Intern(void);
		Intern & operator=(Intern const & rhs);

		AForm * makeForm(std::string formName, std::string target);
};

#endif
