#include <iostream>
#include <fstream>
#include "ticTacToe.h"
#include "ultimateTTT.h"
using namespace std;

UltimateTicTacToe::UltimateTicTacToe()
{
	player = 1;
	turns = 81;
	chooseBoard = 1;
	LastMove = 0;
	t = new ticTacToe * [3];
	for (int i = 0; i < 3; i++)
	{
		t[i] = new ticTacToe[3];
		for (int j = 0; j < 3; j++)
		{
			t[i][j] = ticTacToe();
		}
	}
}

UltimateTicTacToe::~UltimateTicTacToe()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			t[i][j].~ticTacToe();
		}
	}
	delete[] t;
}

int UltimateTicTacToe::get_chooseboard()
{
	return chooseBoard;
}

int UltimateTicTacToe::get_LastMove()
{
	return LastMove;
}

int UltimateTicTacToe::get_turns()
{
	return turns;
}

ticTacToe** UltimateTicTacToe::get_t()
{
	return t;
}

void UltimateTicTacToe::UTinput()
{
	int Bnum, i, j;
	if (chooseBoard == 1)
	{
		cout << "Enter Board Number to play on: ";
		cin >> Bnum;
	}
	else
		Bnum = LastMove;
	switch (Bnum)
	{
	case 1:
		i = 0, j = 0;
		break;
	case 2:
		i = 0, j = 1;
		break;
	case 3:
		i = 0, j = 2;
		break;
	case 4:
		i = 1, j = 0;
		break;
	case 5:
		i = 1, j = 1;
		break;
	case 6:
		i = 1, j = 2;
		break;
	case 7:
		i = 2, j = 0;
		break;
	case 8:
		i = 2, j = 1;
		break;
	case 9:
		i = 2, j = 2;
		break;
	}

	if (t[i][j].get_winner() == 0 && t[i][j].get_spotsleft() != 0)
	{
		if (player == 1 && turns != 81)
		{
			player = 2;
			t[i][j].set_player(2);
		}
		else if (player == 2)
		{
			player = 1;
			t[i][j].set_player(1);
		}
		int row, col;
		cout << endl;
		cout << "Player " << t[i][j].get_player() << "'s turn in board number " << Bnum;
		cout << endl;
		cout << "Enter the row number of cell: ";
		cin >> row;
		cout << "Enter the column number of cell: ";
		cin >> col;
		cout << endl;

		t[i][j].input(row, col, t[i][j]);
		turns--;
		chooseBoard = 0;
		if (row == 0)
		{
			if (col == 0)
			{
				LastMove = 1;
			}
			else if (col == 1)
			{
				LastMove = 2;
			}
			else if (col == 2)
			{
				LastMove = 3;
			}
		}
		if (row == 1)
		{
			if (col == 0)
			{
				LastMove = 4;
			}
			else if (col == 1)
			{
				LastMove = 5;
			}
			else if (col == 2)
			{
				LastMove = 6;
			}
		}
		if (row == 2)
		{
			if (col == 0)
			{
				LastMove = 7;
			}
			else if (col == 1)
			{
				LastMove = 8;
			}
			else if (col == 2)
			{
				LastMove = 9;
			}
		}
	}
	else
	{
		chooseBoard = 1;
	}
}

int UltimateTicTacToe::UTcheckwin()
{
	int UTwin;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (t[i][j].checkWin() == 1)
				t[i][j].set_winner(1);
			else if (t[i][j].checkWin() == 2)
				t[i][j].set_winner(2);
			else if (t[i][j].checkWin() == 0 && t[i][j].get_spotsleft() == 0)
				t[i][j].set_winner(3);
			else
				t[i][j].set_winner(0);
		}
	}

	//horizontal match
	for (int i = 0; i < 3; i++)
	{
		if (t[i][0].get_winner() == t[i][1].get_winner() && t[i][1].get_winner() == t[i][2].get_winner())
		{
			if (t[i][0].get_winner() == 1)
				UTwin = 1;
			else if (t[i][0].get_winner() == 2)
				UTwin = 2;
			else
				UTwin = 0;
		}
		else
			UTwin = 0;

		if (UTwin == 1 || UTwin == 2)
			return UTwin;
	}

	//vertical match
	for (int j = 0; j < 3; j++)
	{
		if (t[0][j].get_winner() == t[1][j].get_winner() && t[1][j].get_winner() == t[2][j].get_winner())
		{
			if (t[0][j].get_winner() == 1)
				UTwin = 1;
			else if (t[0][j].get_winner() == 2)
				UTwin = 2;
			else
				UTwin = 0;
		}
		else
			UTwin = 0;

		if (UTwin == 1 || UTwin == 2)
			return UTwin;
	}

	//Diagonal match
	if (t[0][0].get_winner() == t[1][1].get_winner() && t[1][1].get_winner() == t[2][2].get_winner())
	{
		if (t[0][0].get_winner() == 1)
			UTwin = 1;
		else if (t[0][0].get_winner() == 2)
			UTwin = 2;
		else
			UTwin = 0;

		if (UTwin == 1 || UTwin == 2)
			return UTwin;
	}
	else
		UTwin = 0;

	if (t[0][2].get_winner() == t[1][1].get_winner() && t[1][1].get_winner() == t[2][0].get_winner())
	{
		if (t[0][2].get_winner() == 1)
			UTwin = 1;
		else if (t[0][2].get_winner() == 2)
			UTwin = 2;
		else
			UTwin = 0;
	}
	else
		UTwin = 0;

	return UTwin;
}

ostream& operator << (ostream& out, const UltimateTicTacToe& x)
{
	int num = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			out << "       BOARD NUMBER: " << num << endl;
			out << x.t[i][j] << endl;
			if(x.t[i][j].get_winner() == 1)
				out << "    Player 1 won board " << num << endl;
			else if (x.t[i][j].get_winner() == 2)
				out << "    Player 2 won board " << num << endl;
			else if (x.t[i][j].get_winner() == 3 && x.t[i][j].get_spotsleft() == 0)
				out << "        Draw board " << num << endl;
			num++;
			out << endl;
		}
	}
	return out;
}