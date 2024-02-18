#pragma once
#include <iostream>
#include <fstream>
#include "ticTacToe.h"
using namespace std;

class UltimateTicTacToe
{
private:
	ticTacToe** t;
	int player;
	int turns;
	int chooseBoard;
	int LastMove;
public:
	UltimateTicTacToe();
	~UltimateTicTacToe();
	int get_chooseboard();
	int get_LastMove();
	int get_turns();
	ticTacToe** get_t();
	void UTinput();
	int UTcheckwin();
	friend ostream& operator << (ostream&, const UltimateTicTacToe&);
	friend ofstream& operator << (ofstream& out, UltimateTicTacToe& a)
	{
		out << a.player << endl;
		out << a.turns << endl;
		out << a.chooseBoard << endl;
		out << a.LastMove << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				out << a.t[i][j];
			}
		}
		return out;
	}
	friend ifstream& operator >> (ifstream& in, UltimateTicTacToe& x)
	{
		in >> x.player;
		in >> x.turns;
		in >> x.chooseBoard;
		in >> x.LastMove;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				in >> x.t[i][j];
			}
		}
		return in;
	}
};
