#ifndef _USE_MATH_DEFINES	//This block of code is needed for M_PI constant
#define _USE_MATH_DEFINES
#include <cmath>			
#endif // _USE_MATH_DEFINES


#include "Point.hpp"	//include the header file of Point
#include "Circle.hpp"	//include the header file of Circle
#include <sstream>	//C++ stream buffering
#include <iostream> // C++ style I/O
using namespace std;

Circle::Circle()	 // Default constructor
{
	Centre_point = Point(0, 0);
	m_radius = 0.0;
}

//constructor
Circle::Circle(const Point& pt, const double& a) : m_radius(a), Centre_point(pt) 
{
}

Circle::Circle(const Circle& c)	//Copy constructor
{
	m_radius = c.m_radius;
	Centre_point = c.Centre_point;
}

Circle::~Circle()	// Destructor
{
}

//Get the radius
double Circle::Radius() const
{
	return m_radius;
}

// Setter member-function for radius
// Modifies object state of data member m_radius
void Circle::Radius(const double& a)
{
	m_radius = a;
}

//get the entrepoint
Point Circle::CentrePoint() const
{
	return Centre_point;
}

//set the centrepoint. 
void Circle::CentrePoint(const Point& pt)
{
	Centre_point = pt;
}

// get a string to describe the circle
string Circle::ToString() const
{
	stringstream ss;
	ss << "Circle radius: " << m_radius << ", Centre Point: " << Centre_point.ToString();

	return ss.str();
}

//get the diameter of circle
double Circle::Diameter() const
{
	return 2 * m_radius;
}

//get the area of circle
double Circle::Area() const
{ 
	return M_PI * pow(m_radius, 2);
}

//get the circumference of circle
double Circle::Circumference() const
{
	return M_PI * m_radius * 2;
}

//overloaded assignment operators

Circle& Circle::operator = (const Circle& source)
{
	if (this == &source)
	{
		cout << "Preclude self-assignment check worked" << endl;
		return *this;
	}
	Centre_point = source.Centre_point;
	m_radius = source.m_radius;
	return *this;
}

// Overloaded Ostream << operator
ostream& operator << (ostream& os, const Circle& c)
{
	os << c.ToString();
	return os;
}



