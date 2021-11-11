/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/

#ifndef LIFECELL_H
#define LIFECELL_H
#include <string>
#include <fstream>
#include <sstream>
#include<iostream>
using namespace std;
//Parent class

class LifeCell
{
protected:
	static const int ROWS{ 45 };
	static const int COLS{ 78 };

	int count{ 0 }, rows{ 0 }, cols{ 0 }; //count is the number of neighbors alive counted
	string pattern;//The index of the initial pattern chosen
	bool bOpen{ false };//States whether the file was opned succesfully

	char cell[ROWS][COLS];//Grid the cells. If '*' -> cell is alive, if '.' -> cell is dead
	char nextCellState[ROWS][COLS];

	void InitializeBoard();//Reads the pattern file and initializes the board
	virtual void GetLivingNeighbors(int r, int c) = 0;
	virtual void UpdateCells() = 0;//Allpy the rules here
	void SetNextState();//Set new states into the cell

public:
	LifeCell();//Default constructor. All cells are dead initially.
	void SetPattern(string pat);//Sets the initial pattern and calls initializeBoard()
	void UpdateBoard();//Calculates the next generation, sets the new values into the grid
	string PrintBoard();//Returns a string of the board for display
	void Clear();//Reset the board to all dead cells
};

#endif
