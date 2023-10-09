/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:01:40 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/09 11:08:19 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& src);
		WrongAnimal& operator=(const WrongAnimal& src);
		virtual ~WrongAnimal();

		std::string const& getType() const;
		void		makeSound() const;

	protected:
		std::string	_type;
};

#endif
