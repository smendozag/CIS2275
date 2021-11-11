/*
Programmer: Sergio Mendoza Gomez
Email: smendozagomez@cnm.edu
Program Name: MendozaP8 - The Game Of life 
*/
#include "Function.h"
#include "LifeCell.h"

void WriteInstructions()
{
	cout << "\nHello and welcome to the \"Game of Life\" the game that creates a cellular automation"
		<< "\nThe game will detect ehether a cell is alive or dead the this will start a the automiton that"
		<< "\nthat will determine how the cells will evolve and change over time.";

}

int pickImplementation()
{
	cout << "\n\nHello What cell model implementation would you like to use:"
		<< "\n1: Conway Cell Rules "
		<< "\n Rule # 1 = Any cell with < 2 live neighbors dies because of 'Underpopulation'"
		<< "\n Rule # 2 = Any cell with 2 or 3 live neigbors lives to the next generation"
		<< "\n Rule # 3 = Any cell with more than three live members dies because of 'Overcrowding'"
		<< "\n Rule # 4 = Any cell will exactly 3 live neighbors becomes live because of 'Reproduction'" << endl

		<< "\n2: Fredkin Cell"
		<< "\n Rule # 1 = A dead cell will become a live cell if 1 or 3 neighbors are alive"
		<< "\n Rule # 2 = A live cell becomes a dead cell if 0, 2 oe 4 neighbors are alive"
		<< "\n Rule # 3 = Otherwise the cell stays the same" << endl

		<< "\n3: Modified Fredkin Cell"
		<< "\n Rule # 1 = If age is < 2 then "
		<< "\n Rule # 1A = A dead cell will become a live cell if 1 or 3 neighbors are alive"
		<< "\n Rule # 2B = A live cell becomes a dead cell if 0, 2 oe 4 neighbors are alive"
		<< "\n Rule # 3C = Otherwise the cell stays the same" 

		<< "\n Rule # 2 = If age is > 2 then"
		<< "\n Rule # 2A = Any cell with < 2 live neighbors dies because of 'Underpopulation'"
		<< "\n Rule # 2B = Any cell with 2 or 3 live neigbors lives to the next generation"
		<< "\n Rule # 2C = Any cell with more than three live members dies because of 'Overcrowding'"
		<< "\n Rule # 2D = Any cell will exactly 3 live neighbors becomes live because of 'Reproduction'" << endl

		<< "\n4: Seeds Cell"
		<< "\n Rule # 1 = All dead cell become live cells if exactly 2 neighbors are alive"
		<< "\n Rule # 2 = All other cells become dead"<<endl

		<< "\n5: Diagonal Cell"
		<< "\n Rule # 1 = If cell has 0 or 4 live neighbors it dies "
		<< "\n Rule # 2 = If cell has 1, 2, or 3 live neighbors then it becomes live"<<endl;

	try
	{
		int cellRules;
		cout << "====#>";
		cin >> cellRules;

		if (cellRules < 1 || cellRules > 5)
		{
			throw cellRules;
		}
		return cellRules;
	}
	catch (int x)
	{
		cout << "\nPlease choose from 1 to 5 ONLY!! You Typed: " << x << endl;

	}
	pickImplementation();
}

string pickInitialPattern()
{
	try
	{
		int patternC;
		cout << "\nWhat pattern would you like to start of with!."
			<< "\n1 = Bar"
			<< "\n2 = Boat"
			<< "\n3 = Galaxy"
			<< "\n4 = Randomness"
			<< "\n5 = Ship" << endl;
		cin >> patternC;
		
		if (patternC < 1 || patternC >5)
		{
			throw patternC;
		}

		string pattern;
		switch (patternC)
		{
		case 1:
			pattern = "bar.txt";
			break;
		case 2:
			pattern = "boat.txt";
			break;
		case 3:
			pattern = "Galaxy.txt";
			break;
		case 4:
			pattern = "Randomness.txt";
			break;
		case 5:
			pattern = "ship.txt";
			break;
		default:
			pattern = "Wrong pattern. Try again";
			break;
		}

		return pattern;
	}
	catch (int x)
	{
		cout << "Wrong choice |Choice: " << x << "|Please choose from 1 to 5.!";
		
	}

	
}


