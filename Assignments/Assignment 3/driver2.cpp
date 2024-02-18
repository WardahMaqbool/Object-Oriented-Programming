#include <iostream>
#include <fstream>
#include "ticTacToe.h"
#include "ultimateTTT.h"
using namespace std;

int main()
{
	cout << "ULTIMATE TIC-TAC-TOE" << endl;
	cout << "Enter: " << endl;
	cout << "1 - to play new game." << endl;
	cout << "2 - to load saved game." << endl;
	cout << "choice: ";

	int option;
	cin >> option;

	UltimateTicTacToe game;

	if (option == 1)
	{
		cout << game;
	}
	else if (option == 2)
	{
		ifstream i;
		i.open("UltimateGame.txt");
		i >> game;
		i.close();
		cout << game;
		cout << endl;
	}

	int UTw = 0, option2 = 0, d = 0;
	for (int i = game.get_turns(); i > 0 && option2 != 4 && UTw == 0 && d != 1; i--)
	{
		cout << "Enter:" << endl;
		cout << "3 - to make a move." << endl;
		cout << "4 - to save game and exit." << endl;
		cout << "choice: ";
		cin >> option2;

		switch (option2)
		{
		case 3:
		{
			game.UTinput();
			while (game.get_chooseboard() == 1)
			{
				game.UTinput();
				if (game.get_chooseboard() == 1)
				{
					cout << "Invalid choice!" << endl;
				}
			}
			UTw = game.UTcheckwin();
			cout << game;
			if (UTw == 1)
				cout << "<<<<PLAYER 1 WON THE ULTIMATE TIC-TAC-TOE>>>>";
			else if (UTw == 2)
				cout << "<<<<PLAYER 2 WON THE ULTIMATE TIC-TAC-TOE>>>>";
			else if (UTw == 0)
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (game.get_t()[i][j].get_winner() != 0)
							d = 1;
						else
						{
							d = 0;
							i = 3;
							j = 3;
						}
					}
				}
				if (d == 1)
				{
					cout << "<<<<DRAW GAME>>>>" <<endl;
				}
			}
			else if (UTw == 0 && i == 1)
				cout << "<<<<DRAW GAME>>>>" << endl;
			break;
		}
		case 4:
		{
			ofstream o;
			o.open("UltimateGame.txt");
			o << game;
			o.close();
			cout << endl << "Game has been saved!" << endl;
			break;
		}
		}
	}
}