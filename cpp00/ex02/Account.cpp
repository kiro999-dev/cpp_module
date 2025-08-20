#include "Account.hpp"
#include <ctime>
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account:: getNbAccounts(void)
{
	return _nbAccounts;
}
int	Account::checkAmount( void ) const
{
	if(this->_amount == 0)
		return(1);
	else
		return(0);
}
int	Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int    Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
Account::Account(int initial_deposit )
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_accountIndex = _nbAccounts;
	std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";created"<<std::endl;
	this->_nbAccounts++;
}
Account:: ~Account(void)
{
	  _displayTimestamp();
	  std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";closed"<<std::endl;
}
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout<<"accounts:"<<getNbAccounts()<<";total:"<<getTotalAmount()<<";deposits:"<<getNbDeposits()<<";withdrawals:"<<getNbWithdrawals()<<std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if(withdrawal > this->_amount)
	{
		 std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<this->_amount<<";withdrawal:refused"<<std::endl;
		 return (false);
	}
	int old = this->_amount;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals += this->_nbWithdrawals;
	_totalAmount -= withdrawal;
	std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<old<<";withdrawal:"<<withdrawal<<";amount:"<<this->_amount<<";nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
	return(true);
}
void	Account::_displayTimestamp(void)
{
	std::time_t tt;
	std::tm* timeinfo;
	char buffer[20];
	
	std::time(&tt);
	timeinfo = std::localtime(&tt);
	strftime(buffer,sizeof(buffer),"%Y%m%d_%H%M%S",timeinfo);
	std::cout<<"["<<buffer<<"] ";
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";deposits:"<<this->_nbDeposits<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

void	Account::makeDeposit(int deposit )
{
	int old = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits += this->_nbDeposits;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<old<<";deposit:"<<deposit<<";amount:"<<this->_amount<<";nb_deposits:"<<this->_nbDeposits<<std::endl;

}