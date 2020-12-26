/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:42:34 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/01 12:42:34 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <iomanip>

Account::Account( int initial_deposit ): _amount(initial_deposit) {

	this->_accountIndex = Account::_nbAccounts;

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" <<
	this->_amount << ";created" << std::endl;

	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_bonusCount = 0;
};
	
Account::~Account( void ) {

	this->_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";amount:" <<
	this->_amount << ";closed" << std::endl;
};


void 	Account::_displayTimestamp( void ) {

	std::time_t time_now = std::time(nullptr);
	std::cout << std::put_time(std::localtime(&time_now), "[%Y%m%d_%OH%OM%OS] ");
}

int		Account::getNbAccounts( void ) {

	return Account::_nbAccounts;
};

int		Account::getTotalAmount( void ) {

	return Account::_totalAmount;
};

int		Account::getNbDeposits( void ) {

	return Account::_totalNbDeposits;
};

int		Account::getNbWithdrawals( void ) {

	return Account::_totalNbWithdrawals;
};


void	Account::displayAccountsInfos( void ) {

	Account::_displayTimestamp();

	std::cout << "accounts:" << Account::_nbAccounts << ";total:" <<
	Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;

};

void	Account::makeDeposit( int deposit ) {

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" 
		<< this->_amount << ";deposit:" << deposit;

	this->_amount += deposit;
	this->_nbDeposits++;

	std::cout << ";amount:" << this->_amount << ";nb_deposits:"
		<< this->_nbDeposits << std::endl;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;


};

bool	Account::makeWithdrawal( int withdrawal ) {

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" 
		<< this->_amount << ";withdrawal:";

	this->_amount -= withdrawal;
	if (this->checkAmount()) {
		this->_amount += withdrawal;
		std::cout << "refused" << std::endl;
		return 1;
	}
	this->_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount <<
		";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return 0;
};

int		Account::checkAmount( void ) const {

	this->_bonusCount++;
//	std::cout << "bonusCount" << this->_bonusCount << std::endl;
	if (this->_amount < 0)
		return 1;
	return 0;
};

void	Account::displayStatus( void ) const {

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" <<
	this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:"
	<< this->_nbWithdrawals << std::endl;
};


int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;
	
