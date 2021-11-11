/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/

#ifndef FREDKINCELL_H
#define FREDKINCELL_H

//Derived class

#include "LifeCell.h"

class FredkinCell: public LifeCell
{
protected:
	virtual void GetLivingNeighbors(int x, int y);
	virtual  void UpdateCells();

public: 
	FredkinCell();
};
#endif