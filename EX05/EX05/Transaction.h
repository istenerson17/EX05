#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include "Date.h"
using namespace std;

class Transaction
{
private:
	Date date;
	char type;
	double amount;
	double balance;
	string description;
public:
	Transaction(double Amount, char Type, double Balance, string Description);
	void Transaction::PrintSummary();
};
#endif