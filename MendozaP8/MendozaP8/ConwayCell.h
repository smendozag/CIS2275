/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/

#ifndef CONWAYCELL_H
#define CONWAYCELL_H

#include "LifeCell.h"
//Derived class
class ConwayCell: public LifeCell
{
protected:
	virtual void GetLivingNeighbors(int x, int y);
	virtual void UpdateCells();


public:
	ConwayCell();

};



#endif