#pragma once
#include <iostream>
using namespace std;

class Account
{
private:
	int accountNumber;
	int accountBalance;
public:
	Account()
	{
		accountNumber = 121;
		accountBalance = 1000;
	}

	Account(int Anum, float Abal)
	{
		accountNumber = Anum;
		accountBalance = Abal;
	}

	void set_Anum(int n) {

		accountNumber = n;
	}
	void set_Abal(float b)
	{
		accountBalance = b;
	}
	int get_Anum()
	{
		return accountNumber;
	}
	int get_Abal()
	{
		return accountBalance;
	}

	virtual void print()
	{
		cout << "Account Number: " << accountNumber << endl;
		cout << "Account Balance: " << accountBalance << endl;
	}

	virtual void debit(float d)
	{
		accountBalance = accountBalance - d;
	}

	virtual void credit(float c)
	{
		accountBalance = accountBalance + c;
	}
};

