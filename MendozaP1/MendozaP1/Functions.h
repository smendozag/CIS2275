#ifndef FUNCTION_H
#define FUNCTION_H
#define FILE_IN "Numbers.txt"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;
const int SIZE = 1000;//constant SIZE integer
void header();
bool readFile(int number[], int& total, string& fileName);
void sort(int number[], int total);
void highLow(int number[], int total, int* pHigh, int* pLow);
double average(int number[], int total);
double median(int number[], int total);
void mode(int number[], int total, vector <int>& rModes, int& rNumMode);
bool writeFile(int total, double average, vector<int> modeValues, int high, int low\
	, double median, int numModes, int numTimes, string& rOutputFileName);




















#endif // !1

