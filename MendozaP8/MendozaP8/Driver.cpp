/*
Programmer: Sergio Mendoza
Email: smendozagomez@cnm.edu
Program Objective: 
*/

#include "LifeCell.h"
#include "ConwayCell.h"
#include"FredkinCell.h"
#include"ModifiedFredkin.h"
#include"Seeds.h"
#include"Function.h"
#include "DiagonalCell.h"

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	//Change color
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(screen, 3);


	LifeCell* pLife[5];

	ConwayCell con;
	FredkinCell fred;
	ModifiedFredkin modFred;
	Seeds seed;
	DiagonalCell diaCell;
	
	
	
	pLife[0] = &con;
	pLife[1] = &fred;
	pLife[2] = &modFred;
	pLife[3] = &seed;
	pLife[4] = &diaCell;

	//Display the instructions
	WriteInstructions();

	char doAgain = 'y';
	do
	{
		int lifeCount = 0;
		//Choose the cell type
		int config = pickImplementation();
		config -= 1;

		//Pick initial pattern an put in pat variable
		string pat = pickInitialPattern();
		
		//Use pat and set pattern;
		pLife[config]->SetPattern(pat);

		do
		{
			pLife[config]->UpdateBoard();
			cout << pLife[config]->PrintBoard();
			Sleep(100);
			system("cls");
			lifeCount++;
		} while(lifeCount <200);

		cout << "\nWould you like to play again(y/n)";
		cin >> doAgain;
	} while(doAgain == 'y');

	cout << "\nThank you for playing the game of life!! Have a geat day!!.";
	return 0;
}