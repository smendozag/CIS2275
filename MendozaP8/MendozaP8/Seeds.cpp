/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/

#include "Seeds.h"


Seeds::Seeds()
{
	//Use this lop though the rows and colums
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cell[i][j] = '.';
		}
	}
}

void Seeds::GetLivingNeighbors(int r, int c)
{
	//Check through each cell
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

void Seeds::UpdateCells()
{

	//apply the rules of the cell

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{

			GetLivingNeighbors(i, j);

			//Live cells
			if(cell[i][j] == '.'&& count ==2)
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

