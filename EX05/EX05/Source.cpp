#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Account.h"
#include "Transaction.h"
#include "Date.h"
using namespace std;

template<typename T>
int linearSearch(T list[], T key, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (key == list[i])
			return i;
	}
	return -1;
}

template<typename T>
bool isSorted(const T list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (list[i] > list[i + 1])
			return false;
		else
			return true;
	}
}

template<typename T>
void shuffle(vector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		int index = rand() % v.size();
		int temp = v[i];
		v[i] = v[index];
		v[index] = temp;
	}
}

int main()
{
	srand(time(NULL));
	//EX05_01 - 12.2 Linear Search - Complete
	int list1[] = { 4, 8, 15, 16, 23, 42 };
	cout << linearSearch(list1, 16, 6) << endl;

	double list2[] = { 4.0, 8.0, 15.0, 16.0, 23.0, 42.0 };
	cout << linearSearch(list2, 8.0, 6) << endl;

	string list3[] = { "Four", "Eight", "Fifteen", "Sixteen", "Twenty-Three", "Forty-Two" };
	string compare = "Forty-Two";
	cout << linearSearch(list3, compare, 6) << endl << endl;

	//EX05_02 - 12.4 Is sorted? - Complete
	cout << isSorted(list1, 6) << endl;

	cout << isSorted(list2, 6) << endl;
	
	cout << isSorted(list3, 6) << endl;//This always returned false. I dont think there is a way to check if it is still sorted numerically if words are assigned.

	//EX05_03 - 12.8 Implement Vector Class - Complete
	vector<int> intVector; //Implementing +vector<elementType()
	int storage, initialValue;
	cout << "\nHow many numbers do you want to store? ";
	cin >> storage;
	cout << "\nWhat number do you want to start at? ";
	cin >> initialValue;

	for (int i = initialValue; i < initialValue + storage; i++)
		intVector.push_back(i); //Implementing +push_back(): void

	cout << endl << "You have stored " << intVector.size() << " numbers." << endl; //Implementing +size(): unsigned const
	cout << "They are: ";
	for (int i = 0; i < intVector.size(); i++)
		cout << intVector[i] << " ";
	cout << endl << endl;

	vector<int> intVector2(12);
	cout << "Replacing the inital value with 0." << endl;
	intVector2.swap(intVector);//Implementing +swap(v2:vector): void
	intVector2[0] = 0;
	cout << "Your vector now stores: ";
	for (int i = 0; i < intVector2.size(); i++)
		cout << intVector2[i] << " ";
	cout << endl << endl;

	cout << "The meaning of life has appeared in your vector. " << endl;
	int meaning = intVector2.size() / 2;
	intVector2.at(meaning) = 42;//Implementing +at(index : int): elementType const
	cout << "Your vector now stores: ";
	for (int i = 0; i < intVector2.size(); i++)
		cout << intVector2[i] << " ";
	cout << endl << endl;

	cout << "Swapping the meaning of life with the end of your vector." << endl;
	int temp = intVector2.at(meaning);
	intVector2.at(meaning) = intVector2.at(intVector2.size()-1);//intVector2.push_back(intVector2.at(intVector2.size()));
	intVector2.at(intVector2.size()-1) = temp;//intVector2.push_back(temp);
	cout << "Your vector now stores: ";
	for (int i = 0; i < intVector2.size(); i++)
		cout << intVector2[i] << " ";
	cout << endl << endl;

	cout << "Removing the last value" << endl;
	intVector2.pop_back();//Implementing +pop_back(): void
	cout << "Your vector now stores: ";
	for (int i = 0; i < intVector2.size(); i++)
		cout << intVector2[i] << " ";
	cout << endl;

	cout << "\nYou removed the meaning of life from your vector." << endl;
	cout << "Your life is now meaningless." << endl;
		cout << "Emptying your vector.You have no choice." << endl;
	intVector2.clear();//Implementing +clear(): void
	if (intVector2.empty() == true)//Implementing +empty(): bool const
		cout << "Your vector is now empty." << endl << endl;

	cout << "Your vector now stores: ";
	for (int i = 0; i < intVector2.size(); i++)
		cout << intVector2[i] << " ";
	cout << endl;

	//EX05_04 - 12.20 Shuffle Vector - Complete
	vector<int> ShuffleVector;
	cout << "\nEnter 10 values: ";
	for (int i = 0; i < 10; i++)
	{
		int userVal;
		cin >> userVal;
		ShuffleVector.push_back(userVal);
	}

	shuffle(ShuffleVector);

	cout << "Your values shuffled are: ";
	for (int i = 0; i < ShuffleVector.size(); i++)
		cout << ShuffleVector[i] << " ";
	cout << endl;
	

	//EX05_04 - 12.25 New Account Class - Complete
	int userId;
	double userBalance, userInterest;
	string name;
	Account A1;

	cout << "\nEnter your id number: ";
	cin >> userId;
	A1.setId(userId);

	cout << "\nEnter your name: ";
	cin >> name;
	A1.setName(name);

	cout << "Enter your balance: $";
	cin >> userBalance;
	A1.setBalance(userBalance);

	cout << "Enter your Annual Interest Rate: ";
	cin >> userInterest;
	A1.setAnnualInterestRate(userInterest);

	double draw, deposit;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter a value to deposit: $";
		cin >> deposit;
		cout << "Your new balance is: $" << A1.Deposit(deposit) << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter a value to withdraw: $";
		cin >> draw;
		cout << "Your new balance is: $" << A1.Withdraw(draw) << endl << endl;
	}
	cout << "Your monthly interest rate is: " << A1.getMonthlyInterestRate() << endl << endl;

	A1.PrintSummary();
	return 0;
}