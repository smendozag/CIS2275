/*
Programmer:Sergio Mendoza
Email:smendozagomez@cnm.edu
Program: MendozaP5
Purpose: This program will use aform to help you book a cruise.
The cruise will include excrusions and write a file with the prices
*/

//File: Date.h

#ifndef _DATE_H
#define _DATE_H



#include <string>
#include<ctime>
#include<sstream>
#include<fstream>


using namespace std;



class Date
{
private:
	int month{ 1 }, day{ 1 }, year{ 1900 };
	static const int dayCount[];
	string description;
	int dayOfYear{ 1 };
	bool bLeap{ false };
	void CalcDayOfYear();
	void DetermineLeapYear();

public:
	Date();
	Date(int m, int d, int y, string desc);
	void SetDate(int m, int d, int y, string desc);
	void SetDesc(string d) { description = d; }

	string GetFormattedDate();

	int GetDayOfYear()const { return dayOfYear; }
	int GetYear()const { return year; }
	int GetMonth()const { return month; }
	int GetDay()const { return day; }
	bool isLeapYear()const { return bLeap; }
	bool ValidateThisDate();
};



#endif