/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:19:41 by imurugar          #+#    #+#             */
/*   Updated: 2023/09/19 19:02:26 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::Fixed( const Fixed &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    // this->setRawBits(rhs.getRawBits());
    *this = rhs;
}

Fixed::Fixed( const int n ) : _fixedPointValue( n << _fractionalBits ) {
    std::cout << "Int constructor called" << std::endl;
	/*
	Ejemplo:
	n = 3.75 ->  11.11
	se desplaza n 8 bits hacia la izquierda
	n = 11000000 -> 192 decimal
	*/
}

Fixed::Fixed( const float n ) : _fixedPointValue( roundf( n * ( 1 << _fractionalBits ) ) ) {
    std::cout << "Float constructor called" << std::endl;
	/*
	Ejemplo:
	n = 3.75 ->  11.11
	1 << _fractionalBits -> se desplaza a 0x01 8 veces hacia la izquierda = 2^8 = 256
	n*256 = 960
	en caso de no ser exacto se redondea
	*/
}

Fixed& Fixed::operator=( const Fixed &rhs ) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << _fractionalBits );
}

int     Fixed::toInt( void ) const {
    return this->_fixedPointValue >> _fractionalBits;
}
