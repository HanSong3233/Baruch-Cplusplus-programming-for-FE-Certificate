#include "Point.hpp"       //include the header file that contains the definition of point. 
#include <iostream>      // C++ style I/O
#include <sstream>		//C++ stream buffering
#include <cmath>
using namespace std;


Point::Point() : m_x(0), m_y(0)//constructor
{
	cout << "Point" << ToString() << "created" << endl;
}

Point::~Point()//destructor
{
	cout << "Point" << ToString() << "deleted" << endl;
}

double Point::GetX()  //set the value of point in X coordinates
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

double Point::DistanceOrigin()//return the distance of point to the origin 
{
	return std::sqrt(m_y*m_y+m_x*m_x);
}

double Point::Distance(Point p)
{
	//return p.GetY();
	return std::sqrt((p.GetX() - m_x)*(p.GetX()- m_x)+(p.GetY() - m_y)*(p.GetY() -m_y));
}