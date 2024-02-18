#include <iostream>
#include <fstream>
#include "ticTacToe.h"
using namespace std;

ticTacToe::ticTacToe()
{
	N = 3;
	player = 1;
	winner = 0;
	spotsleft = N * N;
	board = new char* [N];
	for (int i = 0; i < N; i++)
	{
		board[i] = new char[N];
		for (int j = 0; j < N; j++)
		{
			board[i][j] = ' ';
		}
	}
}

ticTacToe::ticTacToe(int N)
{
	this->N = N;
	player = 1;
	spotsleft = N * N;
	winner = 0;
	board = new char* [N];
	for (int i = 0; i < N; i++)
	{
		board[i] = new char[N];
		for (int j = 0; j < N; j++)
		{
			board[i][j] = ' ';
		}
	}
}

ticTacToe::ticTacToe(const ticTacToe& x)
{
	// x.~ticTacToe();
	delete[] board;
	N = x.N;
	player = x.player;
	winner = x.winner;
	spotsleft = x.N * x.N;
	board = new char* [N];
	for (int i = 0; i < N; i++)
	{
		board[i] = new char[N];
		for (int j = 0; j < N; j++)
		{
			board[i][j] = x.board[i][j];
		}
	}
}

ticTacToe::~ticTacToe()
{
	for (int i = 0; i < N; i++)
	{
		delete[] board[i];
	}
	delete[] board;
	board = nullptr;
}

int ticTacToe::get_N()
{
	return N;
}

int ticTacToe::get_player()
{
	return player;
}

int ticTacToe::get_winner()
{
	return winner;
}

int ticTacToe::get_spotsleft()
{
	return spotsleft;
}

void ticTacToe::set_player(int p)
{
	player = p;
}

void ticTacToe::set_winner(int y)
{
	winner = y;
}

bool ticTacToe::set(int r, int c)
{
	if (board[r][c] == ' ' || board[r][c] == 's')
	{
		char s;
		if (player == 1)
			s = 'X';
		else
			s = 'O';
		board[r][c] = s;
		spotsleft--;
		return true;
	}
	else
		cout << "<<Invalid move!>>" << endl;
	return false;
}

void ticTacToe::input(int r, int c, ticTacToe& x)
{
	bool a = x.set(r, c);
	if (a == true)
	{
		if (x.player == 1)
		{
			x.player = 2;
		}
		else 
			x.player = 1;
	}
}

int ticTacToe::checkWin()
{
	int w = 0;
	//horizontal match
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1 && i < N;)
		{
			if (board[i][j] == board[i][j + 1])
			{
				if (board[i][j] == 'X')
				{
					w = 1;
					j++;
				}
				else if (board[i][j] == 'O')
				{
					w = 2;
					j++;
				}
				else
				{
					w = 0;
					i++;
					j = 0;
				}
			}
			else
			{
				w = 0;
				i++;
				j = 0;
			}
		}
		if (w == 1 || w == 2)
			return w;
	}

	//vertical match
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N - 1 && j < N;)
		{
			if (board[i][j] == board[i + 1][j])
			{
				if (board[i][j] == 'X')
				{
					w = 1;
					i++;
				}
				else if (board[i][j] == 'O')
				{
					w = 2;
					i++;
				}
				else
				{
					w = 0;
					j++;
					i = 0;
				}
			}
			else
			{
				w = 0;
				j++;
				i = 0;
			}
		}
		if (w == 1 || w == 2)
			return w;
	}

	//Diagonal match
	w = 3;
	for (int i = 0, j = 0; i < N - 1 && j < N - 1 && w != 0; i++, j++)
	{
		if (board[i][j] == board[i + 1][j + 1])
		{
			if (board[i][j] == 'X')
				w = 1;
			else if (board[i][j] == 'O')
				w = 2;
			else
				w = 0;
		}
		else
		{
			w = 0;
		}
	}
	if (w == 1 || w == 2)
		return w;

	w = 3;
	for (int i = 0, j = N - 1; i < N - 1 && j >= 1 && w != 0; i++, j--)
	{
		if (board[i][j] == board[i + 1][j - 1])
		{
			if (board[i][j] == 'X')
			{
				w = 1;
			}
			else if (board[i][j] == 'O')
				w = 2;
			else
				w = 0;
		}
		else
		{
			w = 0;
		}
	}
	if (w == 1 || w == 2)
		return w;

	return w;
}

ticTacToe& ticTacToe::operator=(const ticTacToe& x)
{
	if (this != &x)
	{
		// this->~ticTacToe();
		delete[] board;
		N = x.N;
		player = x.player;
		spotsleft = x.spotsleft;
		board = new char* [N];
		for (int i = 0; i < N; i++)
		{
			board[i] = new char[N];
			for (int j = 0; j < N; j++)
			{
				board[i][j] = x.board[i][j];
			}
		}
	}
	return *this;
}

ostream& operator << (ostream& out, const ticTacToe& a)
{
	out << endl;
	out << endl;
	out << "   ";
	for (int x = 0; x < a.N; x++)
		 out <<"    "<< x << "  ";
	out << endl;
	out << endl;
	for (int i = 0; i < a.N; i++)
	{
		out << " " << i <<"  ";
		for (int j = 0; j < a.N; j++)
		{
			out << "   ";
			if (a.board[i][j] != 's')
			{
				out << a.board[i][j];
			}
			else
				out << ' ';
			if (j != a.N - 1)
			{
				out << "  |";
			}
		}
		if (i != a.N - 1)
		{
			out << endl;
			out << "    ";
			for (int L = 0; L < a.N; L++)
			{
				out << "______ ";
			}
		}	
		out << endl;
		out << endl;
	}
	return out;
}