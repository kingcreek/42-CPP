/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:04:36 by imurugar          #+#    #+#             */
/*   Updated: 2024/02/04 18:14:40 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		this->_stack = src._stack;
	return *this;
}

bool RPN::isOperator(const std::string &token)
{
    return token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/';
}

int RPN::performOperation(const std::string &oper, int operand1, int operand2)
{
    if (oper[0] == '+')
        return operand1 + operand2;
    else if (oper[0] == '-')
        return operand1 - operand2;
    else if (oper[0] == '*')
        return operand1 * operand2;
    else if (oper[0] == '/')
    {
        if (operand2 == 0)
            throw std::runtime_error("Error: Division by zero");
        return operand1 / operand2;
    }
    else
        throw std::runtime_error("Error: Invalid operator => " + oper);
}

void RPN::exec(std::string token)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error: Insufficient operands for operator");
		
	int operand2 = _stack.top();
	_stack.pop();
	
	int operand1 = _stack.top();
	_stack.pop();

	 int result = performOperation(token, operand1, operand2);
	_stack.push(result);
}

bool RPN::isNumber(const std::string &str)
{
	if (str[0] == '-' && (str[1] >= '0' && str[1] <= '9')) return true;
	if ((str[0] >= '0' && str[0] <= '9')) return true;
	return false;
}

int RPN::extractNumber(std::string &token, std::istringstream& iss)
{
	int sign = 1;
	std::string str(token);
	if (token[0] == '-')
	{
		str = token.substr(1);
		sign = -1;
	}
	
	if (str.length() == 1)
		return (std::atoi(token.c_str()));
	std::size_t found = str.find_first_not_of("0123456789");
	if (found == std::string::npos) 
		return (std::atoi(token.c_str()));
	int iss_tellg = iss.tellg();
	if (iss_tellg == -1)
		iss.str(str.substr(found));
	else
		iss.str(str.substr(found) + iss.str().substr(iss.tellg()));
    iss.clear();
	return (std::atoi(str.substr(0, found).c_str()) * sign);
}

void RPN::extractOperator(std::string &token, std::istringstream& iss)
{
	std::size_t found = token.find_first_not_of("0123456789");
	if (found == std::string::npos) 
		return;
	int iss_tellg = iss.tellg();
	if (iss_tellg == -1)
		iss.str(token.substr(found + 1));
	else
		iss.str(token.substr(found + 1) + iss.str().substr(iss.tellg()));
    iss.clear();
}

/*
	Function to process expression. The important requirements of the subject for this function are:
	
	• The numbers used in this operation and passed as arguments will always be less
	  than 10. The calculation itself but also the result do not take into account this rule.
	• Your program must process this expression and output the correct result on the
	  standard output.
	• If an error occurs during the execution of the program an error message should be
	  displayed on the standard output.
	• Your program must be able to handle operations with these tokens: "+ - / *"

	------IMPORTANT------

	• So the number cannot be greater than 10, but subject does not say anything about negative numbers, so following the rule a number "-1823" is valid.
	• RPN has no specific rules about how input data is entered.
	  For example, an input expression "9-123*" is valid, which gives us a little more complexity in processing.
	  Although the examples given in the subject and on the correction sheet do not indicate such examples since they always have spaces, they are completely valid.
	
*/
void RPN::processExpression(const std::string &expression)
{
	std::istringstream iss(expression);
    std::string token;

	while (iss >> token)
    {
		// It's a simple number	
		if (isNumber(token)) {
			//if number it's followed by operators, separate it
			int extractedNumber = std::atoi(token.c_str());
			if (token.length() > 1)
				extractedNumber = extractNumber(token, iss);
			if (extractedNumber >= 10)
			{
				std::ostringstream oss;
				oss << extractedNumber;
				throw std::runtime_error("Error: Invalid number => " + oss.str() + " Cannot be greater than 10");
			}
			// Add to stack
            _stack.push(extractedNumber);
		}
		// It's a operator
		else if (isOperator(token)) {
			if (token.length() > 1)
				extractOperator(token, iss);
			exec(token);
		}
		// There are no more conditions so something has gone wrong
		else
            throw std::runtime_error("Error: Invalid token =>" + token);
	}
	if (_stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression");
}

int RPN::getResult() const
{
	if (_stack.empty())
		throw std::runtime_error("Error: No result available");
	return _stack.top();
}
