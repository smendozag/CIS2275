/*
Programmer:Sergio Mendoza
Email:smendozagomez@cnm.edu
Program: MendozaP5
Purpose: This program will use aform to help you book a cruise.
The cruise will include excrusions and write a file with the prices
*/

#include "AlaskanCruise.h"

//Static class variable
int AlaskanCruise::resNumber = 0;

AlaskanCruise::AlaskanCruise(string resName, int numPass, int numDays, int numEx, Date& booking, Date& departure):reservation{ resName }, 
numberOfPass{ numPass }, numberDaysCruise{ numDays }, numberOfExcursions{ numEx }, book{ booking }, dep{ departure }
{
	ValidateDate();
	if (bValidDate) 
	{
	CalculateFare();
	resNumber++;
	}
}

void AlaskanCruise::CalculateFare()
{
	//figure out the days from the booking date to the departure date 
	if (dep.GetYear() == book.GetYear())
	{
		numDaysToDepart = dep.GetDayOfYear() - book.GetDayOfYear();
	}
	else
	{
		numDaysToDepart = dep.GetDayOfYear() + 365 - book.GetDayOfYear();
	}

	//Declare excursion price variable
	double excursionPrice = 325.00;

	//Use ternanry operator to set fare for 7 or 9 days
	fare = numberDaysCruise == 7 ? FARE_SEVEN : FARE_NINE;

	//Multiply the the fare set above to be multiplied by the number of passengers
	fare *= numberOfPass;

	if (numDaysToDepart < DAYS_TO_DEPART_REQD)//If departure date is less than 90
	{
		fare = fare - (fare *DISCOUNT_PERCENT / 100.0);//give discount
	}
	else if (numDaysToDepart > DAYS_TO_DEPART_REQD)//If departure is greater than 90
	{
		fare;//Give fare without discount
	}
		if (numberOfExcursions == 0)//If number of excursions is 0
		{
			fare;//Give fare
		}
		else if(numberOfExcursions >0)//If number of excursions is more than 0 
		{
			//Multiply the number of excursions by the the price and add to fare
			fare += excursionPrice * numberOfExcursions;
		}
}

void AlaskanCruise::ValidateDate()
{
	//Try to prove variable is true
	bValidDate = false;

	//If not a valid departure date then display dateString error
	if (!dep.ValidateThisDate())
	{
		dateString = "Departure date is invalid!";
	}
	//If not a valid booking date then display dateString error
	else if (!book.ValidateThisDate())
	{
		dateString = "Booking date is invalid!";
	}
	else {
		//If departure date is before booking display error
		if (dep.GetDayOfYear() < book.GetDayOfYear()) 
		{
			dateString = "Departure date comes before booking date!";
		}
		else if (dep.GetDayOfYear() == book.GetDayOfYear())
		{
			dateString = "You cannot leave the same day as booking";
		}
		else {
			//If You booked 2 years in advance then display dateString error
			if (dep.GetYear()-book.GetYear() > 1)
			{
				dateString = "Departure year can only be the current year or following year!";
			}
			else {
				//If none of the errors were dispayed then make prove bvalidDate true
				bValidDate = true;
				dateString = "Success, dates are valid!";
			}
		}
	}
	
}

void AlaskanCruise::WriteReservationConfirmation()
{
	//start as false to prove variable true
	bWrite = false;
	filename += reservation+" Reservation #" + to_string( resNumber) + ".txt" ;
	ofstream output;//create output object
	output.open(filename);
	//If file not found display dateString error
	if (!bWrite)
	{
		bWrite = false;
		dateString = "Error Reservation File not written ";
	}
	else 
	{
		output << dateString;

		bWrite = true;//bWrite proved true
	}
}




void AlaskanCruise::SetDates(Date& bk, Date& dpt)
{
	//Assign the departure and book Date object to the class public data members 
	book = bk;
	dep = dpt;
	//Call private member method ValidateDate()
	ValidateDate();
	if (!bValidDate)// If bValidDate is true then
	{
		dateString;
	}
	else
	{
		CalculateFare();//Call private member method CalculateFare()
		ReservationDescription();//Call private member methodReservationDescription()
		resNumber++;
	}
}

string AlaskanCruise::ReservationDescription()
{
	//Check is its not bValidDate if not return dateString;
	if (!bValidDate) { dateString; }
	else
	{
		//Declare ss object from stringstream
		stringstream ss;
		ss << "Reservation Name: " << reservation;
		ss << "\r\nThe Number of passengers is: " << numberOfPass;
		ss << "\r\nNumber of days spending in the cruise: " << numberDaysCruise;
		ss << "\r\nYou chose to take " << numberOfExcursions << " excursions";

		ss << "\r\n\r\nYour Booking day is: " << book.GetMonth() << '/' << book.GetDay() << '/' << book.GetYear() << endl;
		ss << "\r\nYour departure day is: " << dep.GetMonth() << '/' << dep.GetDay() << '/' << dep.GetYear() << endl;
		ss << "\r\nReservation Number: " << resNumber << endl;
		ss << "\r\n\r\nThe total Price is " << fare << endl;

		WriteReservationConfirmation();
		//Check if bWrite is false
		if (!bWrite)
		{
			dateString = "File was not written!";//Display this if bWrite is returned as false
		}
		{
			dateString = "The file was written to: ";//if bWrite is true them display dateString
		}
		ss << "\r\n" << dateString<<filename;
		dateString = ss.str();
	}
	return dateString;// ss.str();
}


