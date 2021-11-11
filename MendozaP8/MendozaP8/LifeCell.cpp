/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/

#include "Lifecell.h"

using namespace std;


LifeCell::LifeCell()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cell[i][j] = '.';
		}

	}
}

void LifeCell::SetPattern(string pat)
{
	pattern = pat;
	InitializeBoard();
}

void LifeCell::UpdateBoard()
{
	UpdateCells();
}

void LifeCell::Clear()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cell[i][j] = '.';
		}
	}
}

void LifeCell::InitializeBoard()
{
	ifstream input;
	string filename = pattern;
	input.open(filename);
	if (!input)
		bOpen = false;
	else 
	{
		input >> rows >> cols;
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				input >> cell[i][j];
			
			}
		}
		bOpen = true;
	}
}

void LifeCell::SetNextState()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cell[i][j] = nextCellState[i][j];
		}
	}
}

string LifeCell::PrintBoard()
{
	stringstream ss;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (cell[i][j] == '.')
				ss << '.';
			else
				ss << '*';
		}
		ss << "\n";

	}
	return ss.str();
}
