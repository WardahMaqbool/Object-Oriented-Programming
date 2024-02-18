#include <iostream>
#include "account.h"
#include "currentAccount.h"
#include "savingAccount.h"
using namespace std;

int main()
{
	Account** alist = new Account * [3];
	alist[0] = new savingAccount;
	alist[1] = new CurrentAccount;
	alist[2] = new Account;
	//Print data of all accounts polymorphic behavior
	for (int i = 0; i < 3; i++)
	{
		alist[i]->print();
		cout << endl;
	}
	//credit and debit polymorphic behavior
	alist[0] -> credit(50);
	alist[0]->print();

	cout << endl;
	alist[2] -> debit(333);
	alist[2]->print();

	for (int i = 0; i < 3; i++)
		delete alist[i];
	delete[] alist;
}