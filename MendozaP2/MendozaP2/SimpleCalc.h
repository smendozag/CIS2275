/*
Programmer: Sergio Mendoza Gomez
Email: Smendozagomez@cnm.edu
Program Name: MendozaP2 - Simple Calculater Class
*/

#ifndef _SIMPLECALC_H
#define _SIMPLECALC_H
#include <string>
#include <iostream>
#include<sstream>
using namespace std;
void WriteHeader();

class SimpleCalc
{
	private:
		char operation{ '+' };	//which arithmetic operation is chosen
		double operand1{ 0.0 };
		double operand2{1.0};
		double answer{ 0.0 };	//the answer in numerical form
		string results{};	//formatted string
		string desc;	//description of the operation (optional)	
		void Calculate();
	public:
		SimpleCalc();	//default constructor		
		void SetOperation(char oper, double op1, double op2);//set function to pass data into object
		string GetResults();//get function to get all operator functions







};



#endif // !1

