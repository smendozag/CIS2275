/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/

#ifndef MODIFIEDFREDKINCELL_H
#define MODIFIEDFREDKINCELL_H

//Derived class
#include "ConwayCell.h"
#include"FredkinCell.h"
#include"LifeCell.h"

using namespace std;

class ModifiedFredkin : public FredkinCell
{
private: 
	int age[ROWS][COLS];
	virtual void GetLivingNeighbors(int x, int y);
	virtual void UpdateCells();
public:
	ModifiedFredkin();

};
#endif

