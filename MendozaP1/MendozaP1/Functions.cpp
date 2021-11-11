#include "Functions.h"

void header()
{
	//Header Function 
	cout << "Hello my name is Sergio Mendoza and I present to you my Program" << endl
		<< "Program Name: MendozaP1 Arrays and statistics" << endl
		<< "Program objective is to read the data file\"Numbers.txt\"" << endl
		<< "then the program will display the average, median, mode(s)\n"
		<< "and high and low values\n\n";
}

bool readFile(int nums[], int& rTotal, string& fileName)
{
	rTotal = 0;//Number of integers in file declaration 
	ifstream input;//get input from ifstream class
	input.open(FILE_IN);//use type open to open input file
	if (!input)//if not unput
	{
		return false;
	}
	int i = 0;
	int line;
	while (!input.eof())
	{
		input >> line;//cin==input to line
		nums[i] = line;//Array nums at i loop get put into line
		//cout << line << endl;//cout line
		i++;
		rTotal++;
	}

	input.close();
	return true;
}

void sort(int number[], int total)
{
	int i, j, temp;//define variables 
	for (i = 0; i < total; i++)//First loop to read file
	{
		for (j = 1; j < total - i; j++)//Then second loop to compare values to the first loop 
		{
			if (number[j-1] > number[j])//if number array at index j-1 is greater than number at index j
			{
				temp = number[j];//add number[j] to temp variable
				number[j] = number[j-1];//Make numbers[j-1] equal temp
				number[j-1] = temp;//Make temp equal numbers[j-1] which is equal as number[j]
			}
		}
	}
}

void highLow(int number[], int total, int* pHigh, int* pLow)
{
	*pHigh = *pLow = number[0];//Declare Pointer pHigh and pLow to number at index [0]

	for (int j = 1; j < total; j++)//loop through array
	{
		if (*pLow > number[j])//If array at pLow is greater than number[j]
			*pLow = number[j];//Make pointer pLow the new value

	}

	for (int i = 1; i < total; i++)
	{
		if (*pHigh < number[i])
			*pHigh = number[i];

	}
}
double average(int number[], int total)
{
	double average, sum = 0;//Declare average and sum to equal to 0
	for (int i = 0; i < total; i++)//Loop through number array
	{
		sum += number[i]; //Add all number in the array together
	}
	average = sum / total;//After adding array together get average
	return average;

}
double median(int number[], int total)
{
	sort(number, total);//sort numbers
	int middle = 0;
	double average = 0, median = 0;
	middle = total / 2.0;//Find middle of sorted numbers
	if (total % 2)//if total has 2 remaiders values then
	{
		//Get the two remaider values and add them together
		//after adding values together devide by 2
		median = (number[middle] + number[middle + 1]) / 2.0;
	}
	else {
		return median;//if no remaider values then return median
	}
return median;
}
void mode(int number[], int total, vector <int>& rModes, int& rNumMode)
{
	int rNumModes, maxFreq;
	int j = 0;
	rNumModes = 0;
	maxFreq = 0;
	while (j < total)//while j loop is less than total(979) do this
	{
		int current = number[j];//make number[j] loop = current// have same values
		int localFreq = 0;//declare localFrequency to count how many values the mode has
		while (current == number[j])//while current has the same value as number[j] do this
		{
			++localFreq;
			++j;
		}
		if (localFreq > maxFreq)//if current local value is greater than 0 do this
		{
			if (rModes.size() > 0) 
			{
				if (rNumMode == localFreq) 
				{
					rModes.push_back(current);
				}
				else if (localFreq > rNumMode) 
				{
					rNumMode = localFreq;
					rModes.clear();
					rModes.push_back(current);
				}
			}
			else 
			{
				rNumMode = localFreq;
				rModes.push_back(current);
			}
		}
	}

}
bool writeFile(int total, double average, vector<int> modeValues, int high, int low\
	, double median, int numModes, int numTimes, string& rOutputFileName)
{
	bool summary = true;
	if (!summary)
	{
		cout << "\nSummary not found" << endl;
		return false;
	}
	else
	{
		cout << "The total number of items on the file are: " << total << "\n\n";
		cout << "the lowest value is: " << low;
		cout << "\t\tthe highest value is: " << high << "\n\n";
		cout << "The median is: " << median << "\n\n";
		cout << "The average is: " << average << "\n\n";
		cout << "The modes are ";
		for (int i = 0; i < modeValues.size(); i++)
		{
			cout << modeValues[i] << ", ";
		}
		cout << "they occur a total of " << numTimes << "\n\n";


		cout << "The name of the file is : " << FILE_IN << "\n\n";
		return true;
	}

	return summary;
}