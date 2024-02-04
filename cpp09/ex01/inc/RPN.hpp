/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:03:42 by imurugar          #+#    #+#             */
/*   Updated: 2024/02/04 17:39:46 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN
{

private:
	std::stack<int> _stack;
	
	bool isOperator(const std::string &token);
    int  performOperation(const std::string &oper, int operand1, int operand2);
	bool isNumber(const std::string &str);
	void exec(std::string token);
	int extractNumber(std::string &token, std::istringstream& iss);
	void extractOperator(std::string &token, std::istringstream& iss);

public:
	RPN();
	RPN(const RPN &);
	RPN &operator=(const RPN &);
	~RPN();

	void processExpression(const std::string &expression);
    int getResult() const;

};

#endif
