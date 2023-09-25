/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:18:50 by imurugar          #+#    #+#             */
/*   Updated: 2023/09/19 15:03:51 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


int main() {
    Point vertexA(0.0, 0.0);
    Point vertexB(4.0, 0.0);
    Point vertexC(2.0, 3.0);

    // Imprimir los puntos que forman el triángulo (representación)
    std::cout << "Triángulo ABC:" << std::endl;
    std::cout << "A: (" << vertexA.getX().toFloat() << ", " << vertexA.getY().toFloat() << ")" << std::endl;
    std::cout << "B: (" << vertexB.getX().toFloat() << ", " << vertexB.getY().toFloat() << ")" << std::endl;
    std::cout << "C: (" << vertexC.getX().toFloat() << ", " << vertexC.getY().toFloat() << ")" << std::endl;

    // Representación gráfica del triángulo en estilo ASCII
    std::cout << "Representación gráfica del triángulo:" << std::endl;
    std::cout << "   C" << std::endl;
    std::cout << "  / \\" << std::endl;
    std::cout << " /   \\" << std::endl;
    std::cout << "A-----B" << std::endl;

    // Prueba 1
    std::cout << std::endl;
	
    Point testPoint1(2.0, 1.5);
    std::cout << "Test 1, punto en el medio del triángulo:" << std::endl;
    if (bsp(vertexA, vertexB, vertexC, testPoint1)) {
        std::cout << "El punto (" << testPoint1.getX().toFloat() << ", " << testPoint1.getY().toFloat() << ") está dentro del triángulo." << std::endl;
    } else {
        std::cout << "El punto (" << testPoint1.getX().toFloat() << ", " << testPoint1.getY().toFloat() << ") está fuera del triángulo." << std::endl;
    }

    // Mostrar la representación del triángulo con 'X' en el punto
    std::cout << "   C" << std::endl;
    std::cout << "  / \\" << std::endl;
    std::cout << " / X \\" << std::endl;
    std::cout << "A-----B" << std::endl;

    // Prueba 2
    std::cout << std::endl;
	
    Point testPoint2(0.0, 1.0);
    std::cout << "Test 2, punto fuera del triángulo:" << std::endl;
    if (bsp(vertexA, vertexB, vertexC, testPoint2)) {
        std::cout << "El punto (" << testPoint2.getX().toFloat() << ", " << testPoint2.getY().toFloat() << ") está dentro del triángulo." << std::endl;
    } else {
        std::cout << "El punto (" << testPoint2.getX().toFloat() << ", " << testPoint2.getY().toFloat() << ") está fuera del triángulo." << std::endl;
    }

    // Mostrar la representación del triángulo con 'X' en el punto
    std::cout << "   C" << std::endl;
    std::cout << "  / X \\" << std::endl;
    std::cout << " /   \\" << std::endl;
    std::cout << "A-----B" << std::endl;

    // Prueba 3
    std::cout << std::endl;
	
    Point testPoint3(2.0, 0.0);
    std::cout << "Test 3, punto en el borde del triángulo:" << std::endl;
    if (bsp(vertexA, vertexB, vertexC, testPoint3)) {
        std::cout << "El punto (" << testPoint3.getX().toFloat() << ", " << testPoint3.getY().toFloat() << ") está dentro del triángulo." << std::endl;
    } else {
        std::cout << "El punto (" << testPoint3.getX().toFloat() << ", " << testPoint3.getY().toFloat() << ") está fuera del triángulo." << std::endl;
    }

    // Mostrar la representación del triángulo con 'X' en el punto
    std::cout << "   C" << std::endl;
    std::cout << "  / \\" << std::endl;
    std::cout << " /   \\" << std::endl;
    std::cout << "A-----X" << std::endl;

    return 0;
}