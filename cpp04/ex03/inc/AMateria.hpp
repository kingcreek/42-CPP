/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:01:49 by imurugar          #+#    #+#             */
/*   Updated: 2023/10/17 15:36:25 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
# include <iostream>

class ICharacter;

class AMateria
{
protected:
    std::string _type;
	bool		_state;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(AMateria const & src);
    virtual ~AMateria();

	AMateria& operator=(AMateria const &hrs);
    std::string const & getType() const;
    virtual AMateria*   clone() const = 0;
    virtual void        use(ICharacter& target);
	void		setState(bool state);
	bool		getState() const;
};

#endif
