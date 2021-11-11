/*
Programmer: sergio mendoza
Email: smendozagomez@cnm.edu
File: mendoza
*/
#include"Functions.h"


int main()
{
	vector<int>mValues;//declare Vector
	int  number[1000], total, pLow, pHigh, numModes, rNumMode;//declare variables to run program
	string fileName;//Declare varaibel for file name
	//declare reference to low, high, modes, and filename
	int& lRef = pLow;
	int& HRef = pHigh;
	int& modeRef = numModes;
	string& fileRef = fileName;

	header();
	//declare readfile funtion and put it in result
	bool result = readFile(number, total, fileName);

	//use result to check if file was opened
	if (result == false)
	{
		cout << "\nError, Check file";
	}

	sort(number, total);//Sort function
	highLow(number, total, &pHigh, & pLow);//declare highLow function
	int avg =average(number, total); //declare average funtion to avg variable
	double med = median(number, total);//declare median funtion to med variable
	mode(number, total, mValues, rNumMode);//declare mode functions
	bool summary = writeFile(total, avg, mValues ,pHigh ,pLow ,med ,numModes, rNumMode, fileName );//declare writeFile Function to summary variable
	cin.get();
	return 0;
}