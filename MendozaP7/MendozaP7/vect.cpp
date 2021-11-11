/*
Programmer: Sergio Mendoza Gomez
Email:smendozagomez@cnm.edu
Program Info: This program will take a distance and how long each step is then it will
calculate howm many step it takes to get travel that distance
*/

// vect.cpp -- methods for the Vector class
#include <cmath>
#include<string>
#include <sstream>
#include "vect.h"   // includes <iostream>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::string;
using std::stringstream;

namespace VECTOR
{
    // compute degrees in one radian
    const double Rad_to_deg = 45.0 / atan(1.0);
    // should be about 57.2957795130823

    // private methods
    // calculates magnitude from x and y
    void Vector::CalcMagnitude()
    {
        magnitude = sqrt(x * x + y * y);
    }

    void Vector::CalcAngle()
    {
        if (x == 0.0 && y == 0.0)
            angle = 0.0;
        else
            angle = atan2(y, x);
    }

    // set x from polar coordinate
    void Vector::CalcX()
    {
        x = magnitude * cos(angle);
    }

    // set y from polar coordinate
    void Vector::CalcY()
    {
        y = magnitude * sin(angle);
    }

    // public methods
    //Vector::Vector()             // default constructor
    //{
    //    x = y = magnitude = angle = 0.0;
    //    mode = RECT;
    //}

    // construct vector from rectangular coordinates if form is r
    // (the default) or else from polar coordinates if form is p
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
         {
             x = n1;
             y = n2;
             CalcMagnitude();
             CalcAngle();
        }
        else if (form == POL)
        {
             magnitude = n1;
             angle = n2 / Rad_to_deg;
             CalcX();
             CalcY();
        }

    }

    // reset vector from rectangular coordinates if form is
    // RECT (the default) or else from polar coordinates if
    // form is POL
    void Vector:: SetInfo(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
         {
             x = n1;
             y = n2;
             CalcMagnitude();
             CalcAngle();
        }
        else if (form == POL)
        {
             magnitude = n1;
             angle = n2 / Rad_to_deg;
             CalcX();
             CalcY();
        }

    }

    void Vector::SetPolarMode()    // set to polar mode
    {
        mode = POL;
    }

    void Vector::SetRectMode()     // set to rectangular mode
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector& b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector& b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-()
    {
        x *= -1.0;
        y *= -1.0;
        CalcAngle();
        return *this;
    }

    Vector Vector::operator*(double n)
    {
        x *= n;
        y *= n;
        CalcAngle();
        CalcMagnitude();
        return *this;
    }

    void Vector::Header()
    {
        cout << "\nProgrammer: Sergio Mendoza Gomez \nEmail: smendozagomez@cnm.edu" << std::endl
            << "Program Objective: This program will summulate a person walking from a lamppost" << std::endl
            << "as the person walks their steps vary randomly by from one step to another this program " << std::endl
            << "will calculate how many steps it will take you to reach the target distance" << std::endl
            << "\nIn vector terms this means adding up a sequence of randomly oriented vectors until magnitude" << std::endl
            << "of the sum exceeds 50 feet";  
    }

    // display rectangular coordinates if mode is RECT,
    // else display polar coordinates if mode is POL
    string Vector::GetFormattedResult()
    {
		stringstream ss;
        if (mode == Vector::RECT)
             ss << "(x,y components) = (" << x << ", " << y << ")";
        else if (mode == Vector::POL)
        {
             ss << "(magnitude,angle) = (" << magnitude << ", "
                 << angle * Rad_to_deg << ")";
        }

        return ss.str(); 
    }

}  // end namespace VECTOR
