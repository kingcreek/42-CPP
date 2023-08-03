/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:52:21 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/01 11:17:11 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed   area( Point const a, Point const b, Point const c ) {
    return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
             ( b.getX() * ( c.getY() - a.getY() ) ) +
             ( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = area(a, b, c);

    Fixed pabArea = area(point, a, b);
    Fixed pbcArea = area(point, b, c);
    Fixed pcaArea = area(point, c, a);

	// El punto está en un vértice del triángulo
    if (pabArea == 0 || pbcArea == 0 || pcaArea == 0) 
        return false;
    
	// El punto está en el borde del triángulo
    if ((pabArea < 0 || pbcArea < 0 || pcaArea < 0) ||
        (pabArea > totalArea || pbcArea > totalArea || pcaArea > totalArea))
		return false;

    return (pabArea + pbcArea + pcaArea) == totalArea;
}