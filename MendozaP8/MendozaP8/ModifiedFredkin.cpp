/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/

#include "ModifiedFredkin.h"
#include <sstream>
#include <Windows.h>
using namespace std;

void ModifiedFredkin::GetLivingNeighbors(int r, int c)
{


	FredkinCell::GetLivingNeighbors(r, c);

	if (age[r][c] > 2)
	{
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


}

void ModifiedFredkin::UpdateCells()
{
	//Assign all the rules for cell
	// Loop through every cell on the grid
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				GetLivingNeighbors(i, j);


				if (age[i][j] > 2)
				{
					//conway rules
					if (cell[i][j] == '*' && (count < 2 || count > 3))
					{
						nextCellState[i][j] = '.';
					}
					else {
						nextCellState[i][j] = '*';
						age[i][j]++;
					}

					if (cell[i][j] == '.' && count == 3)
					{
						nextCellState[i][j] = '*';
					}
					else {
						nextCellState[i][j] = '.';
					}
				}
				else 
				{
					//Fredkins cells
					if (cell[i][j] == '*')
					{
						if (count == 0 || count == 2 || count == 4)
						{
							nextCellState[i][j] = '.';
						}
						else{
							nextCellState[i][j] = '*';
							age[i][j]++;
						}

					}

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
		}
		SetNextState();
}

ModifiedFredkin::ModifiedFredkin()
{
	//Loop though the rows and columns

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			age[i][j] = 0;
		}

	}
}
