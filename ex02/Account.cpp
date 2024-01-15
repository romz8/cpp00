/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:24:17 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/15 14:04:52 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>


/*
Initializes the static member variables of the Account class. 
These variables track the total number of accounts, 
the total amount of money in all accounts, the total number of deposits, 
and the total number of withdrawals across all instances of Account.
*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
Get the current time as a time_t object with time_t now = time(0) 
with localtime(&now) Convert the time to a tm structure containing l
then  Output the timestamp in a specific format: [YYYYMMDD_HHMMSS].
tm_year is years since 1900, hence adding 1900.
*/
void	Account::_displayTimestamp() 
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year;
    std::cout << 1 + ltm->tm_mon;
    std::cout << ltm->tm_mday << "_";
    std::cout << ltm->tm_hour;
    std::cout << ltm->tm_min;
    std::cout << ltm->tm_sec << "] ";
}

/*
A static method that displays overall information about all accounts, including 
the total number of accounts, the total amount of money in these accounts, 
and the total numbers of deposits and withdrawals.
*/
void	Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
    << ";deposits:" << _totalNbDeposits << ";withdrawals:" 
    << _totalNbWithdrawals << std::endl;
}

/*
The constructor initializes an account with an initial deposit.
_amount: Sets the initial balance of the account.
_accountIndex: Assigns a unique index to the account and increments the total account count.
_nbDeposits and _nbWithdrawals: Initializes the number of deposits and withdrawals for this account to 0.
Updates the total amount of money in all accounts.
Logs the creation of the account with its index and initial amount.
*/
Account::Account(int initial_deposit) : _amount(initial_deposit) 
{
    _accountIndex = _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/*
The destructor logs the closure of an account.
It displays the account index and the final amount before the account is closed.
*/
Account::~Account() 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/*
- This method handles deposit transactions in an account.
- deposit: The amount to be deposited.
- _amount: Updates the current balance by adding the deposit.
- _totalAmount: Updates the total amount across all accounts.
- _totalNbDeposits and _nbDeposits: Increments the count of 
total deposits and the number of deposits for this account.
- Logs the transaction details, including the account index, previous amount, 
deposit amount, new balance, and the updated number of deposits.
*/
void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

/*
Manages withdrawal transactions from an account.
withdrawal: The amount to be withdrawn.
Checks if the current balance is sufficient for the withdrawal. 
If not, the transaction is refused and the method returns false.
If the transaction is valid, updates the account balance by deducting the withdrawal amount.
Updates the total amount and increments the withdrawal counters.
Logs the transaction details, including the account index, 
previous amount, withdrawal amount, new balance, and the updated number of withdrawals.
*/
bool	Account::makeWithdrawal(int withdrawal) 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if (_amount < withdrawal) {
        std::cout << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
	_nbWithdrawals++;
     std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
     return true;
 }

/*
Displays the current status of an account.
Includes the account index, current balance, number of deposits, and number of withdrawals.
Uses _displayTimestamp to prepend a timestamp to the status message.
*/
 void	Account::displayStatus() const 
 {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
    << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
