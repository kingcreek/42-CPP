/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:04:36 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/31 21:12:44 by imurugar         ###   ########.fr       */
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
	{
		this->_stack = src._stack;
	}	
	return *this;
}

bool RPN::isOperator(const std::string &token)
{
	if (token.length() != 1)
        return (false);
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(const std::string &oper, int operand1, int operand2)
{
    if (oper == "+")
        return operand1 + operand2;
    else if (oper == "-")
        return operand1 - operand2;
    else if (oper == "*")
        return operand1 * operand2;
    else if (oper == "/")
    {
        if (operand2 == 0)
        {
            throw std::runtime_error("Error: Division by zero");
        }
        return operand1 / operand2;
    }
    else
    {
        throw std::runtime_error("Error: Invalid operator");
    }
}

bool RPN::isNumber(const std::string &str)
{
    int operand = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false && str[i] != '-')
            return (false);
        if (str[i] == '-' && i != 0)
            return (false);
        if (str[i] == '-' && i == 0 && str.length() == 1)
            return (false);
        if (str[i] == '-' && i == 0)
            operand++;
    }
    if (operand > 1)
        return (false);
    return (true);
}

void RPN::processExpression(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isNumber(token)) //if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1])))
        {
            // If the token is a number, push it onto the list
            _stack.push(std::atoi(token.c_str()));
        }
        else if (isOperator(token))
        {
            // Token is an operator, pop operands, perform operation, and push result
            if (_stack.size() < 2)
            {
                throw std::runtime_error("Error: Insufficient operands for operator");
            }

            int operand2 = _stack.top();
            _stack.pop();

            int operand1 = _stack.top();
            _stack.pop();

            int result = performOperation(token, operand1, operand2);
            _stack.push(result);
        }
        else
        {
            throw std::runtime_error("Error: Invalid token =>" + token);
        }
    }

    if (_stack.size() != 1)
    {
        throw std::runtime_error("Error: Invalid expression");
    }
}

int RPN::getResult() const
{
    if (_stack.empty())
    {
        throw std::runtime_error("Error: No result available");
    }
    return _stack.top();
}
