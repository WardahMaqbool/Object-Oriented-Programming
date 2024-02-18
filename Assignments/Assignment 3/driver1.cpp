#include <iostream>
#include <fstream>
#include "ticTacToe.h"
using namespace std;

int main()
{
	cout << "TIC-TAC-TOE" << endl;
	cout << "Enter: " << endl;
	cout << "1 - to play new game with NxN sized board." << endl;
	cout << "2 - to play new game with default board." << endl;
	cout << "3 - to load saved game." << endl;
	cout << "choice: ";
	int option;
	cin >> option;

	ticTacToe b;
	switch (option)
	{
	case 1:
	{
		int size;
		cout << "Enter size of board: ";
		cin >> size;
		if (size >= 3)
		{
			ticTacToe a(size);
			b = a;
			cout << a;
			cout << endl;
		}
		else
		{
			cout << "Error: Size sould be greater than or equal to 3!" << endl;
			cout << "Re-enter size: ";
			cin >> size;
			ticTacToe a(size);
			b = a;
			cout << a;
			cout << endl;
		}
		break;
	}
	case 2:
	{
		ticTacToe a;
		b = a;
		cout << a;
		cout << endl;
		break;
	}
	case 3:
	{
		ifstream i;
		i.open("BasicGame.txt");
		ticTacToe a;
		i >> a;
		b = a;
		i.close();
		cout << a;
		cout << endl;
		break;
	}
	}
	int s = b.get_N();
	int q, w = 0, option2 = 1;
	cout << endl;
	cout << endl;
	cout << "Player 1: X  vs Player 2: O "<<endl;
	
	for (q = b.get_spotsleft(); q > 0 && w == 0 && option2 != 2; q--)
	{
		cout << endl;
		cout << "Enter: " << endl;
		cout << "1 - to make a move." << endl;
		cout << "2 - to save game and exit." << endl;
		cout << "choice: ";
		cin >> option2;

		switch (option2)
		{
		case 1:
		{
			int r, c;
			cout << "Player " << b.get_player() << "'s turn"<<endl;
			cout << "Enter the row number of cell: ";
			cin >> r;
			cout << "Enter the column number of cell: ";
			cin >> c;
			b.input(r,c,b);
			cout << b;

			w = b.checkWin();
			b.set_winner(w);
			if (w == 1)
				cout << "        PLAYER 1 WON!";
			else if (w == 2)
				cout << "        PLAYER 2 WON!";
			else if (w == 0 && q == 1)
				cout << "          DRAW GAME!";
			break;
		}
		case 2:
		{
			ofstream o;
			o.open("BasicGame.txt");
			o << b;
			o.close();
			cout << endl << "Game has been saved!" << endl;
			break;
		}
		}
	}
}