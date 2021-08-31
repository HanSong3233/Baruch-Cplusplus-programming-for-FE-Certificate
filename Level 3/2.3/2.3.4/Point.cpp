#include "Point.hpp"       //include the header file that contains the definition of point. 
#include <iostream>      // C++ style I/O
#include <sstream>		//C++ stream buffering
#include <cmath>
using namespace std;


Point::Point() : m_x(0), m_y(0)//default constructor, default value (0,0)
{
	cout << "Point" << ToString() << "created" << endl;
}

Point::Point(double x,double y) : m_x(x), m_y(y)//constructor with initial value (x,y). 
{
	cout << "Point" << ToString() << "created" << endl;
}

Point::Point(const Point& p)	//Copy constructor
{
	m_x = p.m_x;
	m_y = p.m_y;

	cout << "Point" << ToString() << "created in copy constructor."  << endl;
}


Point::~Point()//destructor
{
	cout << "Point" << ToString() << "deleted" << endl;
}

double Point::X() const  //set the value of point in X coordinates
{
	return m_x;
}

double Point::Y() const ////get the value of point in X coordinates
{
	return m_y;
}

void Point::X(double new_X) //set the value of point in X coordinates
{
	m_x = new_X;
}

void Point::Y(double new_Y)  //set the value of point in y coordinates
{
	m_y = new_Y;
}

string Point::ToString() const  //return the string description of the point. 
{
	stringstream ss;
	ss << "(" << m_x << ", " << m_y << ")";

	return ss.str();
}

double Point::Distance() const//return the distance of point to the origin 
{
	return std::sqrt(m_y*m_y+m_x*m_x);
}

double Point::Distance(const Point& p) const//return the distance of point to point, we make it call by reference in this problem. 
{
	//SetX(1); get a complier error if runs.
	return std::sqrt((p.m_x - m_x)*(p.m_x- m_x)+(p.m_y - m_y)*(p.m_y -m_y));
}