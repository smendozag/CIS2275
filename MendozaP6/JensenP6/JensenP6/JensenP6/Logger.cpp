#include "Logger.h"
#pragma warning(disable:4996)

Logger::Logger()
{
	Filename();
	Time();
	output.precision(2);
	output.setf(ios::fixed | ios::showpoint);
	//open file using the member variable output
	output.open((filename).c_str());
	if (!output)
	{
		bLogOpen = false;
	}
	else
	{
		bLogOpen = true;
	}
	//write the first lines in the file



}
void Logger::Filename()
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%m-%d-%y_%I.%M.%S");
	dateTimeStamp = ss.str();
	filename = "Log_" + dateTimeStamp + ".txt";
}

void Logger::Time()
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%X");
	timeNow = ss.str();
}

void Logger::StartLog(double initialBal)
{
	Time();
	output << timeNow << ".\n"
		<< "Game started: Player has $" << initialBal << ".";
}

void Logger::WriteLog(string s)
{
	Time();
	output << timeNow << ".\n"
		<< s;
}

void Logger::CloseLog(string s)
{
	Time();
	output << timeNow << ".\n"
		<< s;
	output.close();
}
