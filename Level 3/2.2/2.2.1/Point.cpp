#include "Point.hpp"       //include the header file that contains the definition of point. 
#include <iostream>      // C++ style I/O
#include <sstream>		//C++ stream buffering
using namespace std;


Point::Point() : m_x(0), m_y(0)//constructor
{
	cout << "point" << ToString() << "created"  << endl;
}

Point::~Point()//destructor
{
	cout << "point" << ToString() << "destroyed"  << endl;
}

double Point::GetX()  //get the value of point in X coordinates
{
	return m_x;
}

double Point::GetY()  ////get the value of point in X coordinates
{
	return m_y;
}

void Point::SetX(double new_X) //set the value of point in X coordinates
{
	m_x = new_X;
}

void Point::SetY(double new_Y)  //set the value of point in y coordinates
{
	m_y = new_Y;
}

string Point::ToString()   //return the string description of the point. 
{
	stringstream ss;
	ss << "(" << m_x << ", " << m_y << ")";

	return ss.str();
}