/*
Programmer:Sergio Mendoza
Email:smendozagomez@cnm.edu
Program: MendozaP5
Purpose: This program will use aform to help you book a cruise.
The cruise will include excrusions and write a file with the prices
*/

//File: Date.cpp


#include "Date.h"



using namespace std;

//Declare dayCount array as a constant
const int Date::dayCount[] = { 31,28,31,30,31,30,
		31,31,30,31,30,31 };

Date::Date()
{
	//Set the Date variables to the computer's date.

	time_t rawtime;
	tm OStime;

	time(&rawtime);

	//Old Way p.389
	//OStime = localtime(&rawtime);

	//New way, not deprecated
	localtime_s(&OStime, &rawtime);

	month = OStime.tm_mon + 1;
	day = OStime.tm_mday;
	year = OStime.tm_year + 1900;

	description = "Today's Date";
	DetermineLeapYear();
	CalcDayOfYear();
}


Date::Date(int m, int d, int y, string desc)
{
	month = m;
	day = d;
	year = y;
	description = desc;
	DetermineLeapYear();
	CalcDayOfYear();
}


void Date::SetDate(int m, int d, int y, string desc)
{
	month = m;
	day = d;
	year = y;
	description = desc;
	DetermineLeapYear();
	CalcDayOfYear();
}


string Date::GetFormattedDate()
{
	stringstream strDate;
	strDate << description;

	string monName[12] = { "January",	"February ","March",
		"April", "May", "June", "July", "August",
		"September", "October", "November", "December" };


	strDate << ": " << monName[month - 1] << " " << day
		<< ", " << year;

	return strDate.str();
}

//Declare the ValidateThisDate() function
bool Date::ValidateThisDate()
{
	//Check if the month is less than 1 and month is more than 12 so out of range
	if (month < 1 || month > 12) {
		return false;
	}
	//Check if its not a leapyear and it not greater than 29 or day is not greater than the actual day or 
	//That day is less than 1
	if ((month == 2 && bLeap && day > 29) || (day > dayCount[month - 1]) || (day < 1)) {
		return false;
	}
	return true;
	
}

void Date::CalcDayOfYear()
{
	//set up array of days in each month
	//for non-leapyear year
	

	dayOfYear = 0;

	//add the days up to the previous month
	for (int i = 1; i < month; ++i)
	{
		dayOfYear += dayCount[i - 1];

		//if adding Feb, check if leap year
		if (i == 2 && bLeap == true)
			dayOfYear += 1;

	}

	dayOfYear += day;
}

void Date::DetermineLeapYear()
{
	//A year is a leap year if it is divisible by four, 
	//unless it is a century date (i.e,  1900). 
	//If it is a century date, it is a leap year only 
	//if it is divisible by 400 (i.e., 2000).

	if (year % 4 == 0 && year % 100 != 0)
		bLeap = true;
	else if (year % 400 == 0)
		bLeap = true;
	else
		bLeap = false;
}


