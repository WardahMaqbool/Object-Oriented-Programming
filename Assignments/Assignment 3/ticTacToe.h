#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class ticTacToe
{
private:
	int N;
	int player;
	int winner;        //added for operations concerning
	int spotsleft;     //class ultimateTicTacToe
	char** board;
public:
	ticTacToe();
	ticTacToe(int N);
	ticTacToe(const ticTacToe&);
	~ticTacToe();
	int get_N();
	int get_player();
	int get_winner();
	int get_spotsleft();
	void set_player(int p);
	void set_winner(int y);
	bool set(int r, int c);
	void input(int r, int c, ticTacToe& x);
	int checkWin();
	ticTacToe& operator=(const ticTacToe& a);
	friend ostream& operator << (ostream&, const ticTacToe&);
	friend ofstream& operator << (ofstream& out, ticTacToe& a)
	{
		out << a.N << endl;
		out << a.player << endl;
		out << a.spotsleft << endl;
		out << a.winner << endl;
		for (int i = 0; i < a.N; i++)
		{
			for (int j = 0; j < a.N; j++)
			{
				if (a.board[i][j] != ' ')
				{
					out << a.board[i][j];
				}
				else
					out << 's';
			}
			out << endl;
		}
		return out;
	}

	friend ifstream& operator >> (ifstream& in, ticTacToe& a)
	{
		a.~ticTacToe();
		in >> a.N;
		in >> a.player;
		in >> a.spotsleft;
		in >> a.winner;
		a.board = new char* [a.N];
		for (int i = 0; i < a.N; i++)
		{
			a.board[i] = new char[a.N];
			for (int j = 0; j < a.N; j++)
			{
				in >> a.board[i][j];
			}
		}
		return in;
	}
};
