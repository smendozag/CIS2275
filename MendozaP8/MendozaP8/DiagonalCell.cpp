#include "DiagonalCell.h"

void DiagonalCell::GetLivingNeighbors(int r, int c)
{

	count = 0;

	//Top right cell
	if (r != 0 && c != COLS - 1)
		if (cell[r - 1][c + 1] == '*')
			count++;

	//cell to the bottow right
	if (r != ROWS - 1 && c != COLS - 1)
		if (cell[r + 1][c + 1] == '*')
			count++;

	//Cell to the bottom left
	if (r != ROWS - 1 && c != 0)
		if (cell[r + 1][c - 1] == '*')
			count++;

	//Cell to upper left
	if (r != 0 && c != 0)
		if (cell[r - 1][c - 1] == '*')
			count++;
}

DiagonalCell::DiagonalCell()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cell[i][j] = '.';
		}

	}
}

void DiagonalCell::UpdateCells()
{
	//loop through every cell in the grid
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			GetLivingNeighbors(i, j);

			//diagonal rules
			if(cell[i][j] == '*')
				if (count == 0|| count == 4)
				{
					nextCellState[i][j] = '.';
				}
				else {
					nextCellState[i][j] = '*';
				}

			//dead cells
			if (cell[i][j] == '.')
				if(count > 0 && count <4)
				{
					nextCellState[i][j] = '*';
				}
				else{
					nextCellState[i][j] = '.';
				}




		}

	}
	SetNextState();
}
