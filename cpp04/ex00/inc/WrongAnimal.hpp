/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:01:40 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/03 10:09:49 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal(std::string const & type);
		virtual ~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & src);

		std::string const &	getType(void) const;
		void		makeSound(void) const;

	protected:
		std::string	_type;
};