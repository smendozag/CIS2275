#ifndef LOGGER_H
#define LOGGER_H

#include <iomanip>
#include <ctime>
#include <string>
#include <chrono>
#include <sstream>
#include <fstream>



using namespace std;
class Logger
{
private:
	string filename;
	bool bLogOpen{ false };
	string timeNow;
	string dateTimeStamp;
	ofstream output;
	void Filename();
	void Time();
public:
	Logger();
	void StartLog(double initialBal);
	void WriteLog(string s);
	void CloseLog(string s);
	bool IsLogOpen() { return bLogOpen; }
};

#endif
