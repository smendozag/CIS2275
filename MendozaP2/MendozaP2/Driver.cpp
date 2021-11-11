/*
Programmer: Sergio Mendoza Gomez
Email: Smendozagomez@cnm.edu
Program Name: MendozaP2 - Simple Calculater Class
*/
#include "SimpleCalc.h"
#include<iostream>
#include<string>
using namespace std;

void WriteHeader();
int main()
{
	SimpleCalc calc;//SimpleCalc object

	WriteHeader();//Header function
	
	//user input varaibles
	double op1 = 0.0, op2 = 1.0;
	char oper = '+';
	char doAgain = 'y';//do again varaible for loop

	do
	{
		//ask the user for their choice of operation 
		cout << "\n\nWhat operation would you like to do?" << endl;
		cout << "\t-----------------" << endl;
		cout << "\t| + | - | * | / |" << endl;
		cout << "\t-----------------" << endl<<"\t";
		cin >> oper;

		//ask for op1 and op2
		cout << "\nPlease choose first value:";
		cin >> op1;
		cout << "\nPlease choose second value:"<< endl;
		cin >> op2;

		//use our object to setOperation 
		calc.SetOperation(oper, op1, op2);

		//Ask calc object for its formatted string 
		string sResults;
		sResults = calc.GetResults();
		cout << sResults;

		cout << "\nWould you like to try again (y/n)";
		cin >> doAgain;

	} while (doAgain == 'y');
	//say good bye
	cout << " Thank you for using my simpleCalc Program" << endl
		<<"Goodbye!!";

	cin.get();
	return 0;

}



