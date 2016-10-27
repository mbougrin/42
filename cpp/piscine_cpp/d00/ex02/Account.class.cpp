/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 16:03:10 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 19:26:27 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>

Account::Account(int initial_deposit) 
{
	_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << initial_deposit;
	std::cout << ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account(void)
{ 
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
	Account::_nbAccounts -= 1;
}

int				Account::getNbAccounts(void) { return (Account::_nbAccounts); }

int				Account::getTotalAmount(void) { return (Account::_totalAmount); }

int				Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }

int				Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

void			Account::displayAccountsInfos(void) 
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:";
	std::cout << Account::_totalNbWithdrawals << std::endl;
}

void			Account::makeDeposit(int deposit) 
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << (this->_amount + deposit); 
	std::cout << ";nb_deposits:" << (this->_nbDeposits + 1) << std::endl;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool			Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if ((this->_amount - withdrawal) < 0)
	{
		std::cout << ";withdrawal:" << "refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << (this->_amount - withdrawal); 
	std::cout << ";nb_withdrawals:" << (this->_nbWithdrawals + 1) << std::endl;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

int				Account::checkAmount(void) const { return (this->_amount); }

void			Account::_displayTimestamp(void) { std::cout << "[20150406_153629] "; }

void			Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
