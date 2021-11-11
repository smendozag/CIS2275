/*
Programmer: Sergio Mendoza Gomez
Email:smendozagomez@cnm.edu
Program Info: This program will take a distance and how long each step is then it will
calculate howm many step it takes to get travel that distance
*/

// vect.h -- Vector class 
#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
#include <string>

namespace VECTOR
{
    class Vector
    {  
	public:
		// RECT for rectangular, POL for Polar modes
		enum Mode {RECT, POL};

    private:
        double x{0.0};          // horizontal value
		double y{0.0};          // vertical value
        double magnitude{0.0};        // length of vector
        double angle{0.0};        // direction of vector in degrees
        Mode mode{RECT};         // RECT or POL

    // private methods for setting values
        void CalcMagnitude();
        void CalcAngle();
        void CalcX();
        void CalcY();

    public:
       Vector() = default;	//default constructor
		//default input parameters constructor
        Vector(double n1, double n2, Mode form = RECT);       

		//Get Methods
        double GetX() const {return x;}       // report x value
        double GetY() const {return y;}       // report y value
        double GetMagnitude() const {return magnitude;}   // report magnitude
        double GetAngle() const {return angle;}   // report angle
		std::string GetFormattedResult();

		//Set Methods
		void SetInfo(double n1, double n2, Mode form = RECT);
        void SetPolarMode();                    // set mode to POL
        void SetRectMode();                     // set mode to RECT

        //Overloaded operator
        Vector operator + (const Vector& b)const; //Adds 2 Vectors
        Vector operator - (const Vector& b)const; //Subtracts one Vector from another
        Vector operator - (); //Unary changes the sign of the current Vector object
        Vector operator * (double n); //Multiplies the current Vector by a double 
        
        void Header();

    };

}   // end namespace VECTOR
#endif
