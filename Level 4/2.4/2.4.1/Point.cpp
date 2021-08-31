#include "Point.hpp"       //include the header file that contains the definition of point. 
#include <iostream>      // C++ style I/O
#include <sstream>		//C++ stream buffering
#include <cmath>
using namespace std;


Point::Point() : m_x(0), m_y(0)//default constructor, default value (0,0)
{
}

Point::Point(double x, double y) : m_x(x), m_y(y)//constructor with initial value (x,y). 
{
}

Point::Point(const Point& p)	//Copy constructor
{
	m_x = p.m_x;
	m_y = p.m_y;
}


Point::~Point()//destructor
{
}

double Point::X() const //set the value of point in X coordinates
{
	return m_x;
}

double Point::Y() const //get the value of point in X coordinates
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

// Negate the coordinates
Point Point::operator - () const
{
	return Point(-m_x, -m_y);
}

// Scale the coordinates
Point Point::operator * (double factor) const
{
	return Point(m_x*factor, m_y*factor);
}

// Add coordinates
Point Point::operator + (const Point& p) const
{
	return Point(m_x + p.m_x, m_y + p.m_y);		// Anonymous object
}

// Equally compare operator
bool Point::operator == (const Point& p) const
{
	return (m_x == p.m_x) && (m_y == p.m_y);
}

// Scale the coordinates & assign
Point& Point::operator *= (double factor)
{
	m_x *= factor;
	m_y *= factor;
	return *this;
}
//assign operator
Point& Point::operator = (const Point& source)
{
	//check to make sure not assigning to myself
	if (this == &source)
	{
		cout << "Preclude self-assignment check worked" << endl;
		return *this;
	}
	{
		m_x = source.m_x;
		m_y = source.m_y;

		return *this;
	}
}

string Point::ToString() const   //return the string description of the point. 
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
	return std::sqrt((p.m_x - m_x)*(p.m_x- m_x)+(p.m_y - m_y)*(p.m_y -m_y));
}