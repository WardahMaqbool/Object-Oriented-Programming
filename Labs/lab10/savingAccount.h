#pragma once
#include <iostream>
#include "account.h"
using namespace std;

class savingAccount : public Account
{
private:
	float interestRate;
public:
	savingAccount()
	{
		interestRate = 0.5;
	}

	savingAccount(float Ir, int Anum, float Abal) : Account(Anum, Abal)
	{
		interestRate = Ir;
	}

	void print()
	{
		cout << "Savings Account Info: " << endl;
		Account::print();
		cout << "Interest Rate: " << interestRate <<endl;
	}

	void credit(float c)
	{
		float a = Account::get_Abal();
		Account::set_Abal(a + c);
	}

	void debit(float d)
	{
		float a = Account::get_Abal();
		if (d <= a)
		{
			Account::set_Abal(a - d);
		}
		else
			cout << "Insufficient Balance";
	}
	~savingAccount() 
	{
		cout <<" ~SavingAccount Destroyed."<< endl;
	}
};

