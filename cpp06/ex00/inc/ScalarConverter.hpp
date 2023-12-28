/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:54:09 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/27 22:24:36 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>

enum type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL_F,
	PSEUDOLITERAL_D,
	UNKNOWN
};


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &rhs);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter &rhs);

		static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);
		
		static void displayChar(std::string& s);
		static void displayInt(std::string& s);
		static void displayFloat(std::string& s);
		static void displayDouble(std::string& s);
		static void displayUnknown();
		static type getType(std::string& str);
		
	public:
		static void convert(std::string &ref);
			
};

#endif
