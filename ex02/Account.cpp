// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <time.h>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit)
{
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->initial_deposit = initial_deposit;
    this->_nbWithdrawals = 0;

    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;

    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";created" << std::endl;

    return;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";closed" << std::endl;

    return;
}

/* 
    Static ones
*/

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/*
    Non static 
*/

void	Account::makeDeposit( int deposit )
{

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";

    this->_amount += deposit;
    this->_totalNbDeposits += 1;
    this->_nbDeposits += 1;

    Account::_totalAmount += deposit;

    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:";

    if (withdrawal <= 0)
    {
        std::cout << "refused" << std::endl;   
        return (false);
    }
    if (this->checkAmount() >= withdrawal)
    {
        std::cout << withdrawal << ";";
        this->_amount -= withdrawal;
        this->_totalAmount -= withdrawal;
        this->_nbWithdrawals += 1;
        this->_totalNbWithdrawals += 1;

        std::cout << "amount:" << this->_amount << ";";
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

        return (true);
    }

    std::cout << "refused" << std::endl;   
    return (false);
}

int		Account::checkAmount( void ) const
{
    return this->_amount;
};

void    Account::_displayTimestamp( void )
{
    char buffer [19];
    struct tm * timeinfo;
    time_t  rawtime = std::time(0);

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,19,"[%G%m%d_%H%M%S] ",timeinfo);

    std::cout << buffer;
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

/* int		Account::checkAmount( void ) const {
    return this->_amount;
}; */