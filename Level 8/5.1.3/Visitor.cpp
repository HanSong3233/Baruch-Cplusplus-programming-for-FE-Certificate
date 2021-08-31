//Implementation file for class Visitor.Ensures type - safe access using Boost.Variant via overloaded() operators below
#include"Visitor.hpp"

Visitor::Visitor() : m_dx(0), m_dy(0) {}

Visitor::Visitor(double a, double b) : m_dx(a), m_dy(b) {}  // Overload constructor that initializes with dx and dy value

Visitor::Visitor(const Visitor& source) : m_dx(source.m_dx), m_dy(source.m_dy) {}  // Copy constructor

Visitor& Visitor::operator = (const Visitor& source)  // Assignment operator
{
	// Check to make sure not assigning to myself
	if (this == &source) return *this;

	// Copy state
	m_dx = source.m_dx;
	m_dy = source.m_dy;

	return *this;
}

Visitor::~Visitor() {}	// Destructor

// Visit a point
// Overload operator() for Point
// Change coordinates of the reference point object by member data points m_dx and m_dy
void Visitor::operator () (Point& p) const
{
	p.X(p.X() + m_dx);
	p.Y(p.Y() + m_dy);
}

// Visit a Line
// Change coordinates of the reference Line's Point objects - Start and End - by member data points m_dx and m_dy
// by using operator() (Point& p) using references to change the start_point and end_point
void Visitor::operator () (Line& l) const
{

	
	// Obtain line's start and end points
	Point& Start_Point = l.start();
	Point& End_Point = l.end();

	(*this)(Start_Point); // modify the start_point by calling this object's operator() (Point &p)
	l.start(Start_Point);  // Now visit line's start point.

	(*this)(End_Point);  // Call this object's operator() (Point &p)
	l.end(End_Point);  // Now visit line's end point
}

// Visit a Line
// Change coordinates of the reference Line's Point objects - Start and End - by member data points m_dx and m_dy
// by using operator() (Point& p) using references to change the start_point and end_point
void Visitor::operator () (Circle& c) const
{
	Point& CentrePoint = c.CentrePoint();  // Obtain circle's CentrePoint 
	(*this)(CentrePoint);  // modify the start_point by calling this object's operator() (Point &p)
	c.CentrePoint(CentrePoint); // Now visit line's start point.
}