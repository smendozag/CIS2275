/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/

#ifndef DIAGONALCELL_H
#define DIAGONALCELL_H
#include "LifeCell.h"
using namespace std;

class DiagonalCell: public LifeCell
{
protected:
	virtual void GetLivingNeighbors(int x, int y);
	virtual void UpdateCells();

public:
	DiagonalCell();

};

#endif
