#pragma once 
#include <iostream>
#include "account.h"
using namespace std;

class CurrentAccount : public Account
{
private:
	float ServiceCharges;
	float minBalance;
public:
	CurrentAccount()
	{
		ServiceCharges = 30;
		minBalance = 100;
	}

	CurrentAccount(float SC, float mB, int Anum, float Abal) :Account(Anum, Abal)
	{
		ServiceCharges = SC;
		minBalance = mB;
	}

	void print()
	{
		cout << "Current Account Info:" << endl;
		Account::print();
		cout << "Minimum Balance: " << minBalance << endl;
		cout << "Service Charges: " << ServiceCharges << endl;
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
			if (a < minBalance)
			{
				Account::set_Abal(a - ServiceCharges);
			}
			Account::set_Abal(a - d);
		}
		else
			cout << "Insufficient Balance";
	}
	~CurrentAccount() 
	{
		cout<<" ~CurrentAccount Destroyed."<< endl;
	}
};

