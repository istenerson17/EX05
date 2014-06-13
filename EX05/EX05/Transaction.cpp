#include <iostream>
#include <string>
#include "Transaction.h"
using namespace std;

Transaction::Transaction(double Amount, char Type, double Balance, string Description)
{
	Date date = Date();
	amount = Amount;
	type = Type;
	balance = Balance;
	description = Description;
}

void Transaction::PrintSummary()
{
	cout << "Date of Transaction: "  << date.getMonth() << " " << date.getDay() << " " << date.getYear() << endl;
	cout << "Type of Transaction: " << type << endl;
	cout << "Amount of Transaction: " << amount << endl;
	cout << "New Balance: $" << balance << endl;
	cout << "Description of Transaction: " << description << endl << endl;
}