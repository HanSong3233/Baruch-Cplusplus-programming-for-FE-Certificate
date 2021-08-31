// Header file for class Visitor. Ensures type-safe access using Boost.Variant via overloaded () operators below, due to the requirement
// that the class must implement boost::static_visitor<T>.
// This class must overload operator() for every type used by the boost::variant variable it acts on.
#ifndef Visitor_HPP
#define Visitor_HPP
#include "Circle.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "boost\variant\variant.hpp"
using namespace std;

class Visitor : public boost::static_visitor<> {
private:
	double m_dx;
	double m_dy;

public:
	//constructor and destructor
	Visitor();
	Visitor(double a, double b);  // Overload constructor that initializes with dx and dy value
	Visitor::Visitor(const Visitor& source);
	virtual ~Visitor();

	//overloaded assignment operator
	Visitor& operator = (const Visitor&source);

	//set function
	void operator () (Point& p) const;   //visit a point
	void operator () (Line& l) const;    //visit a line 
	void operator () (Circle& c) const;     //visit a circle

};

#endif