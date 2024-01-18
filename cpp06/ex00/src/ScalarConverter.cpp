/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ScalarConverter.cpp								:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: imurugar <imurugar@student.42madrid.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/12/27 18:47:48 by imurugar		  #+#	#+#			 */
/*   Updated: 2023/12/28 17:26:16 by imurugar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& other) {
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& rhs) {
	(void) rhs;
	return *this;
}

void ScalarConverter::displayChar(std::string& s) {
	
	int i = static_cast<int>(s[0]);
	float f = static_cast<float>(s[0]);
	double d = static_cast<double>(s[0]);

	if (std::isprint(s[0]))
		std::cout << "char: '" << s[0] << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (i > static_cast<int>(std::numeric_limits<int>::max()))
		std::cout << "int: Overflow" << std::endl;
	else if (i < static_cast<int>(std::numeric_limits<int>::min()))
		std::cout << "int: Underflow" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	std::cout.precision(10);
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::displayInt(std::string& s) {
	double d = static_cast<double>(strtod(s.c_str(), NULL));
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (std::isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: Overflow" << std::endl;
	else if (d < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: Underflow" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::displayFloat(std::string& s) {
	
	double d = static_cast<double>(strtod(s.c_str(), NULL));
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (std::isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: Overflow" << std::endl;
	else if (d < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: Underflow" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout.precision(10);
	if (f - floorf(f) == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (d - floor(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::displayDouble(std::string& s) {
	
	double d = static_cast<double>(strtod(s.c_str(), NULL));
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: Overflow" << std::endl;
	else if (d < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: Underflow" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout.precision(10);
	if (f - floorf(f) == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (d - floor(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void displayLiteralFloat(const std::string &literal)
{
	std::cout << "char:\t Impossible"	<< std::endl;
	std::cout << "int:\t Impossible"	<< std::endl;
	std::cout << "float:\t "			<< literal << std::endl;
	std::cout << "double:\t "			<< literal.substr(0, literal.length() - 1) << std::endl;
}

void displayLiteralDouble(const std::string &literal)
{
	std::cout << "char:\t Impossible"	 << std::endl;
	std::cout << "int:\t Impossible"	  << std::endl;
	std::cout << "float:\t "			  << literal + "f" << std::endl;
	std::cout << "double:\t "			 << literal << std::endl;	
}

void ScalarConverter::displayUnknown() {
	std::cout << "char: Impossible"		<< std::endl;
	std::cout << "int: Impossible"		<< std::endl;
	std::cout << "float: Impossible"	<< std::endl;
	std::cout << "double: Impossible"	<< std::endl;
}

bool ScalarConverter::isInt(const std::string &literal)
{
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			continue;
		if (!isdigit(literal[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	int dot = 0;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			continue;
		if (literal[i] == '.')
			dot++;
		else if (!isdigit(literal[i]))
			return (false);
	}
	return (dot == 1);
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	int dot = 0;
	if (literal[literal.length() - 1] != 'f')
		return (false);
	for (size_t i = 0; i < literal.length() - 1; i++)
	{
		if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
			continue;
		if (literal[i] == '.')
			dot++;
		else if (!isdigit(literal[i]))
			return (false);
	}
	return (dot == 1);
}

type ScalarConverter::getType(std::string& str) {
	
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (PSEUDOLITERAL_F);
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (PSEUDOLITERAL_D);
	if (isInt(str))
		return (INT);
	if (str.length() == 1)
		return (CHAR);
	if (isFloat(str))
		return (FLOAT);
	if (isDouble(str))
		return (DOUBLE);
	return (UNKNOWN);
}

void ScalarConverter::convert(std::string& str) {
	
	type t = ScalarConverter::getType(str);
	
	switch(t){
		case CHAR:
			displayChar(str);
			break;
		case INT:
			displayInt(str);
			break;
		case FLOAT:
			displayFloat(str);
			break;
		case DOUBLE:
			displayDouble(str);
			break;
		case PSEUDOLITERAL_F:
			displayLiteralFloat(str);
			break;
		case PSEUDOLITERAL_D:
			displayLiteralDouble(str);
			break;
		default:
			ScalarConverter::displayUnknown();
	}
	
}
