#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include "Transaction.h"
using namespace std;

class Account
{
private:
	int id;
	double balance;
	double annualInterestRate;
	string name;
	
public:
	vector<Transaction> transactions;

	Account();
	Account(string Name, int Id, double Balance);

	int getId();
	int setId(int newId);
	double getBalance();
	double setBalance(double newBalance);
	string getName();
	void setName(string Name);
	double getAnnualInterestRate();
	double setAnnualInterestRate(double newInterest);

	double getMonthlyInterestRate();
	double Withdraw(double amount);
	double Deposit(double amount);
	void PrintSummary();
};
#endif