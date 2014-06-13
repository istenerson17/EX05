#include <iostream>
#include <vector>
#include <string>
#include "Account.h"
using namespace std;

Account::Account()
{
	id = 0;
	balance = 0;
	annualInterestRate = 0;
}

Account::Account(string Name, int Id, double Balance)
{
	name = Name;
	id = Id;
	balance = Balance;
}

int Account::getId()
{
	return id;
}

int Account::setId(int newId)
{
	id = newId;
	cout << endl;
	return id;
}

double Account::getBalance()
{
	return balance;
}

double Account::setBalance(double newBalance)
{
	balance = newBalance;
	cout << endl;
	return balance;
}

string Account::getName()
{
	return name;
}

void Account::setName(string Name)
{
	name = Name;
}

double Account::getAnnualInterestRate()
{
	return annualInterestRate;
}

double Account::setAnnualInterestRate(double newInterest)
{
	annualInterestRate = newInterest;
	cout << endl;
	return annualInterestRate;
}

double Account::getMonthlyInterestRate()
{
	double monthly = (getAnnualInterestRate() / 12);
	return monthly;
}

double Account::Withdraw(double amount)
{
	char type = 'W';
	int newBalance = getBalance() - amount;
	string Description = "Withdrawral";
	Transaction T1(amount, type, newBalance, Description);
	transactions.push_back(T1);
	setBalance(newBalance);
	return newBalance;
}

double Account::Deposit(double amount)
{
	char type = 'D';
	int newBalance = getBalance() + amount;
	string Description = "Deposit";
	Transaction T1(amount, type, newBalance, Description);
	transactions.push_back(T1);
	setBalance(newBalance);
	return newBalance;
}

void Account::PrintSummary()
{
	cout << "Transaction Summary: " << endl;
	cout << "Holder's name: " << name << endl;
	cout << "Interest Rate: " << annualInterestRate << endl;
	cout << "Balance: $" << balance << endl;
	cout << "Transactions: " << endl;
	for (int i = 0; i < transactions.size(); i++)
		transactions[i].PrintSummary();
}