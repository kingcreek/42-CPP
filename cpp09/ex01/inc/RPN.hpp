/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:03:42 by imurugar          #+#    #+#             */
/*   Updated: 2023/12/31 21:13:00 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN
{

private:
	std::stack<int> _stack;
	bool isOperator(const std::string &token);
    int performOperation(const std::string &oper, int operand1, int operand2);

public:
	RPN();
	RPN(const RPN &);
	RPN &operator=(const RPN &);
	~RPN();

	void processExpression(const std::string &expression);
    int getResult() const;

};

#endif
