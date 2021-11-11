#ifndef FUNTIONS_H
#define FUNCTIONS_H
#include<iostream>
#include<array>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

void WriteHeader();
const int SIZE = 1000;
class ArrayAnalyzer
{
private:
	array<int, SIZE> n = {};//array declaration 
	int total{ 0 };	//total number of ints read into the array 
	double average{ 0.0 }, median{ 0.0 };
	
	string filename = { "Numbers.txt" };//input file
	string strModes{ "" };//formatted string with modes and frequency
	bool bOpen{ false };//true if file is opened, false if not
	
	void Read();//read the data, if possible, sets bOpen flag		
	void Sort();//sorts the array, low to high 
	void Median();
	void Average();
	void Mode();
public:
	ArrayAnalyzer();//constructor//job is to initialize class data
	explicit ArrayAnalyzer(string filein);//overloaded constructor, is passed file 

	void SetFile(string filein);//pass in file that contains the numbers, must be 1000 or less
								
	//returns true if file opened and data read,false if file not opened
	//programmer should check this before calling other functions!
	bool IsFileOpened();	
	int GetTotal()const { return total; }//returns total number of values read
	double GetMedian()const { return median; }
	double GetAverage() { return average; }
	void GetHighLow(int& rHigh, int& rLow);
	string GetModes()const { return strModes; }

	//returns true if found, false if not.howMany of that value found, 0 if none 
	bool FindValue(int value, int& howMany);
	
	//writes the header, input file name, total, average, median, high, low, modes
	bool WriteSummary(string fileout);
};
#endif // !
