/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:32:37 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/10 19:30:59 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "closed" << std::endl;
}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}
int	Account::getTotalAmount()
{
	return _totalAmount;
}
int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" <<  _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	if(withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
	}else{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
	}
	return (_amount >= withdrawal);
}
int		Account::checkAmount() const
{
		return (_amount);
}
void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" <<  _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
	

void	Account::_displayTimestamp()
{
	std::time_t t = std::time(NULL);
    std::string timestamp;
    timestamp.resize(20);
    std::strftime(&timestamp[0], timestamp.size(), "[%Y%m%d_%H%M%S] ", std::localtime(&t));
    std::cout << timestamp << std::flush;
}
