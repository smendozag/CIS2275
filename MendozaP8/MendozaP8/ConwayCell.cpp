/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/
//Inpementation file - ConwayCell.cpp
#include "ConwayCell.h"


ConwayCell::ConwayCell()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cell[i][j] = '.';
		}

	}
}


void ConwayCell::GetLivingNeighbors(int r, int c)
{
	//Initialize count
	count = 0;

	//Find out where each cell is at all 8 of them
	//Top right cell
	if (r != 0 && c != COLS - 1)
		if (cell[r - 1][c + 1] == '*')
			count++;

	//Cell to the right
	if (c != COLS - 1)
		if (cell[r][c + 1] == '*')
			count++;

	//cell to the bottow right
	if (r != ROWS - 1 && c != COLS - 1)
		if (cell[r + 1][c + 1] == '*')
			count++;

	//Cell to the bottom
	if (r != ROWS - 1)
		if (cell[r + 1][c] == '*')
			count++;

	//Cell to the bottom left
	if (r != ROWS - 1 && c != 0)
		if (cell[r + 1][c - 1] == '*')
			count++;

	//Cell to the left
	if (c != 0)
		if (cell[r][c - 1] == '*')
			count++;

	//Cell to upper left
	if (r != 0 && c != 0)
		if (cell[r - 1][c - 1] == '*')
			count++;
	//cell to top
	if (r != 0)
		if (cell[r - 1][c] == '*')
			count++;
}

void ConwayCell::UpdateCells()
{
	//Apply the rules to each cell

	//Loop through every cell on the grid
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{

			GetLivingNeighbors(i, j);

			//COnway Rules
			//Live Cells
			if (cell[i][j] == '*')
			{
				if (count < 2 || count >3)
					nextCellState[i][j] = '.';
				nextCellState[i][j] = '*';

			}

			//dead cells
			if (cell[i][j] == '.')
			{
				if (count == 3)
					nextCellState[i][j] = '*';
				else
					nextCellState[i][j] = '.';


			}



		}
		
	}
	SetNextState();
}



