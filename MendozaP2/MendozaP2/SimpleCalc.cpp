/*
Programmer: Sergio Mendoza Gomez
Email: Smendozagomez@cnm.edu
Program Name: MendozaP2 - Simple Calculater Class
*/

#include "SimpleCalc.h"
void WriteHeader()
{
	//WriteHeader function
	cout << "Hello my name is sergio Mendoza, and I present to you my program\n"
		<< "Course #: CIS 2275\n Program: MendozaP2\n"
		<< "MendozaP2 will be a simple calculator that will let you do some of the\n"
		<<"following oerations +, -, /,and * \n"
		<<"after it will return your result and give the option to exit or try another";
}

SimpleCalc::SimpleCalc() {}//default constructor

void SimpleCalc::SetOperation(char oper, double op1, double op2)
{
	//Set private data member variables to SetOperation method
	operation = oper;
	operand1 = op1;
	operand2 = op2;
	string desc, results;
}

//The code that does the caculation
void SimpleCalc::Calculate()
{
	//Use switch statement to check for operation then you the math
	switch (operation)
	{
	case'+':
		answer = operand1 + operand2;
		desc = " addition";
		break;
	case'-':
		answer = operand1 - operand2;
		desc = " subtraction";
		break;
	case'*':
		answer = operand1 * operand2;
		desc = " multiplication";
		break;
	case'/':
		if (operand2 == 0.0)//Check that devision by 0 is not used
		{
			desc = " Error! No division by 0!";//error desciption message
		}
		else {
			answer = operand1 / operand2;//Do the division math
			//set a different description
			desc = " division";
		}
		break;
	default:desc = "that is not recognized operation";

	}
}

string SimpleCalc::GetResults()
{
	//Call calculate to use the values and dispaly then in a string
	Calculate();
	stringstream results;// use stringstream insert the data member variables to results
	
	//Formatted String
	results << "You choose" << desc << " : " << operand1
		<< operation << operand2 <<" = "<< answer;
	
	return results.str();//Return as datatype string
}

