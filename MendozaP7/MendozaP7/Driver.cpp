/*
Programmer: Sergio Mendoza Gomez
Email:smendozagomez@cnm.edu
Program Info: This program will take a distance and how long each step is then it will 
calculate howm many step it takes to get travel that distance
*/


#include"vect.h"
#include<iostream>
#include<random>
#include<chrono>
#pragma 

int main()
{
	using namespace std;
	using VECTOR::Vector;
	std::default_random_engine engine;
	double direction{ 0.0 };
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps{ 0 };
	double target{ 0.0 };
	double dstep{ 0.0 };
	char answer{ 'y' };

	//Seed random
	engine.seed(chrono::system_clock::now().time_since_epoch().count());

	//Display header
	Vector header;
	header.Header();



	do
	{
		//Ask for the input for target distance
		cout << "Please type the target distance(in ft): ";
		cin >> target;

		//Ask the user for the step size
		cout << "Please type in the size of the step(in ft): ";
		cin >> dstep;

		//caculate how many steps are needed	
		while (result.GetMagnitude() < target)
		{



			//Create a distribution angle (0,359);
			uniform_int_distribution<unsigned int> angle(1, 359);
			direction = angle(engine);

			//add the step in that direction to the result.
			//use the setInfo method to set the dstep and the direction
			//Vector::POL
			step.SetInfo(dstep, direction, Vector::POL);

			//Use overloaded operator to add result and step;
			result = result + step;

			//increment steps
			steps++;

			//reset step to 0,0
			step.SetInfo(0.0, 0.0, Vector::RECT);
		}



		cout << "\nAfter " << steps << " steps, the subject has the following location: \n";
		cout << result.GetFormattedResult() << endl;

		result.SetPolarMode();

		cout << "or\n"<< result.GetFormattedResult() << endl;
		cout << "Average outward distance per step = "<< result.GetMagnitude() / steps << " (ft)"<< endl;

		cout << "\n\nWould you like to try another lamppost?(y/n)";
		cin >> answer;

		if (answer == 'y')
		{
			//reset variables
			result.SetInfo(0.0, 0.0, Vector::RECT);
			step.SetInfo(0.0, 0.0, Vector::RECT);
		}
	}
	while (answer == 'y');
	cout << "\nGood bye! Have a good day";
	return 0;
}