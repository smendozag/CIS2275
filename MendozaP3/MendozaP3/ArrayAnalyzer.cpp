/*
Programmer: Sergio Mendoza
Email: smendozagomez@cnm.edu
Program: MendozaP3
*/

#include "ArrayAnalyzer.h"

void WriteHeader()
{
	cout << "Programmer: Sergio Mendoza" << endl
		<< "Email : smendozagomez@cnm.edu" << endl
		<< "Program : MendozaP3" << endl
		<< "Welcome to \"Array Analyzer\" program" << endl
		<< "this program will read a file then display" << endl
		<< "average, median, modes, high, and low values" << endl;
}
ArrayAnalyzer::ArrayAnalyzer() {}

ArrayAnalyzer::ArrayAnalyzer(string filein):filename{filein}
{	Read();
	if (bOpen)
	{	cout << "Found the file: " << filein;
		Sort();
		GetTotal();
		Average();
		Median();
	}
	else {
		cout << "The file was not found";
	}
}
void ArrayAnalyzer::SetFile(string filein)
{	filename = filein;
	Read();
	if (bOpen)//if bopen is true
	{	//invoke the private methods
		Sort();
		GetTotal();
		Median();
		Average();
		Mode();
		bOpen = true;
	}
}
bool ArrayAnalyzer::IsFileOpened() 
{
	return bOpen;//Return bOpen whether it is true or false
}

void ArrayAnalyzer::Read() 
{	total = 0;
	ifstream input;//open if stream
	input.open(filename);//Check if file is open 
	if (!input)//Not input file then
	{
		bOpen = false;//set bOpen to false
	}
	else {
		int i = 0;//Declare i for loop
		int line;//Declare line to put in file numbers
		while ((!input.eof()) && i < SIZE)//While it not at end of file(eof) and i is less than SIZE then
		{
			input >> line;//Make input equal line
			n[i] = line;//Make array value = line
			i++;
			total++;
		}
		bOpen = true;
	}
	
	input.close();
}

void ArrayAnalyzer::Sort()
{

	int j = 0;
	sort(n.begin(), n.begin() + (total));//Sort using Sort() function 
	int i = 0;

}

void ArrayAnalyzer::Median()
{

	int middle = 0;
	middle = total / 2.0;//Find middle of sorted numbers
	if (total % 1)//if total has 1 remaiders values then
	{
		median = n[middle];
	}
	else {
		
		//Get the two remaider values and add them together
		//after adding values together devide by 2
		median = (n[middle] + n[middle + 1]) / 2.0;
		//return median;//if no remaider values then return median
	}
}

void ArrayAnalyzer::Average()
{
	double sum = 0;//Declare average and sum to equal to 0
	for (int i = 0; i < total; i++)//Loop through number array
	{
		sum += n[i]; //Add all number in the array together
	}
	average = sum / total;//After adding array together get average
	
}

void ArrayAnalyzer::GetHighLow(int& rHigh, int& rLow)
{
	
	rLow = rHigh = 0;
	rLow =  n[0];//Lowest value is now the first value int the sorted array
	rHigh = n[total -1];//Highest value is now the last value in the sorted array

}

void ArrayAnalyzer::Mode()
{
	vector<int>mValues;//declare vector for values
	int rNumMode, maxFreq;
	int j = 0;
	rNumMode = 0;
	maxFreq = 0;
	int current = 0;
	stringstream ss;
	while (j < total)//while j loop is less than total(979) do this
	{
		int current = n[j];//make number[j] loop = current// have same values
		int localFreq = 0;//declare localFrequency to count how many values the mode has
		while (current == n[j])//while current has the same value as number[j] do this
		{
			++localFreq;
			++j;
		}
		if (localFreq > maxFreq)//if current local value is greater than 0 do this
		{
			if (mValues.size() > 0)//If mValues size is larger than 0 then 
			{
				if (rNumMode == localFreq)//if rNumModes is equivalent to localFreq 
				{
					mValues.push_back(current);//Add to mValues
					ss << "\nCurrent value: " << current << "number of modes: " << rNumMode;//add to ss
				}
				else if (localFreq > rNumMode)//if localFreq is equivalent to rNumModes then
				{
					rNumMode = localFreq;//make rNumMode = localFreq
					mValues.clear();//Clear mValues then
					mValues.push_back(current);//Add new values
					
					ss << "\nCurrent value: " << current << "number of modes: " << rNumMode;//Add to ss
				}
			}
			else
			{
				rNumMode = localFreq;//If all above does not happen then mae rNumMode = localFreq then
				mValues.push_back(current);//Add mValues to current 
				ss << "\nCurrent value: "<<current<< "number of modes: " <<rNumMode;//Add to ss
			}
		}
	}
	//Loop threw strModes
	for (int i = 0; i < mValues.size(); i++)
		cout << strModes;
	strModes = ss.str();
}

bool ArrayAnalyzer::WriteSummary(string fileout) 
{
	int rHigh, rLow;
	ofstream output;
	output.open(fileout);
	if (!output)
	{
	}
	else
	{
		GetHighLow(rHigh, rLow);
		output << "\nThe Total number is: " << total;
		output << "\nThe median is: " << median;
		output << "\nThe average is: " << average;
		output << "\nThe high value is: " << rHigh;
		output << "\nThe low value is: " << rLow;
		output << strModes;
		return true;
	
	}

}

//bool ArrayAnalyzer::FindValue(int value, int& howMany)
//{
//	bool findValue = true;
//
//	string intModes = GetModes();
//	int mode = 0;
//	intModes = static_cast<int>(mode) ;
//	for (int i = 0; i < total; i++)
//		if (value == mode)
//		{
//			return true;
//		}
//		else
//		{
//
//			return false;
//		}
//		
//	return value;
//}

