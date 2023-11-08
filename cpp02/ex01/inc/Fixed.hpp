/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:20:13 by imurugar          #+#    #+#             */
/*   Updated: 2023/09/18 16:46:29 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed( const Fixed &rhs );
	
	Fixed( const int rhs );
	Fixed( const float rhs );
	
    Fixed& operator=( const Fixed &rhs );
	
    ~Fixed();

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif
