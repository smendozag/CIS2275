/*
Programmer: Sergio Mendoza
Email: smendozagomez@cnm.edu
Program: MendozaP3
*/
#include "ArrayAnalyzer.h"

int main()
{
	WriteHeader();
	string filein = "";
	string fileout = "";
	int total = 0, rLow = 0, rHigh = 0;// , value = 0, howMany = 0, fValue = 0;
	double average, median;
	string strModes;

	cout << "Please type the name of the file: " << endl;
	cin >> filein;

	//Create object
	ArrayAnalyzer nums;
	nums.SetFile(filein);
	bool bRead = nums.IsFileOpened();
	if (bRead)
	{


		total = nums.GetTotal();
		average = nums.GetAverage();
		median = nums.GetMedian();
		nums.GetHighLow(rHigh, rLow);
		strModes = nums.GetModes();
		
		//fValue = nums.FindValue(value, howMany);


		if (!bRead)
		{
			cout << "\nThe file was not found";
		}
		else
		{


			cout << "\nThe Total number is: " << total;
			cout << "\nThe median is: " << median;
			cout << "\nThe average is: " << average;
			cout << "\nThe high value is: " << rHigh;
			cout << "\nThe low value is: " << rLow;
			cout << strModes;
		}
		bool bOpen = nums.WriteSummary(fileout);

		cout << "\nplease type the name of the summary file: ";
		cin >> fileout;
		if (!bOpen)
		{
			cout << "File was not written";
		}
		else
		{
			cout << "\nWrote all the files to summary";
			total = nums.GetTotal();
			average = nums.GetAverage();
			median = nums.GetMedian();
			nums.GetHighLow(rHigh, rLow);
			strModes = nums.GetModes();

			return true;
		}

		/*int repeat = 1;
		do {
			cout << "Would you like to search for a value";
			cin >> value;
			if (fValue)
			{
				cout << value << "found value. With a total number of: " << howMany << " times";
			}
			else
			{
				cout << "\nThe value is " << value << " Which was only found : 0 times";
			}



			cout << "\nhello";
			cin.get();

		} while (repeat == 1);*/

		return 0;
	}
}
