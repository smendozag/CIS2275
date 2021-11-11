/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life
*/

#ifndef SEEDS_H
#define SEEDS_H


#include "LifeCell.h"
class Seeds: public LifeCell
{
protected:
	virtual void GetLivingNeighbors(int x, int y);
	virtual  void UpdateCells();

public:
	Seeds();

};
#endif
