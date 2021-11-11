/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/

#include "FredkinCell.h"

void FredkinCell::GetLivingNeighbors(int r, int c)
{
	count = 0;
	//Ckeck every cell
	//Cell to the right
	if (c != COLS - 1)
		if (cell[r][c + 1] == '*')
			count++;

	//cell to the bottom
	if (r != ROWS - 1)
		if (cell[r + 1][c] == '*')
			count++;

	//Cell to the left
	if (c != 0)
		if (cell[r][c - 1] == '*')
			count++;
	//Cell to the top
	if (r != 0)
		if (cell[r - 1][c] == '*')
			count++;



}

void FredkinCell::UpdateCells()
{
	//Apply the rules ir each cell

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			GetLivingNeighbors(i, j);

			//Live cells
			if (cell[i][j] == '*')
			{
				if (count == 0 || count == 2 || count == 4)
				{
					nextCellState[i][j] = '.';
				}
				else {
					nextCellState[i][j] = '*';
				}
			}

			//Dead cells
			if (cell[i][j] == '.')
				if (count == 1 || count == 3)
				{
					nextCellState[i][j] = '*';
				}
				else {
					nextCellState[i][j] = '.';
				}
			
		}
	}

	SetNextState();
}

FredkinCell::FredkinCell()
{
	//Loop triugh rows and collums
}



