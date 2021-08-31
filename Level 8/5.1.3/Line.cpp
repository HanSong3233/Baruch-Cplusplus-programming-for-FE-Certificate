#include "Point.hpp"  //include the header file for Point class
#include "Line.hpp"  //include the header file for line class.
#include <iostream>  //C++ style I/O
#include <sstream>   ////C++ stream buffering
using namespace std;

Line::Line(): Shape(), Start_point(0,0),End_point(0,0) //default constructor
{

}

Line::~Line()//destructor
{

}

Line::Line(const Point& p1, const Point& p2): Shape(), Start_point(p1),End_point(p2) //constructor
{

}

Line::Line(const Line& l):Shape(l),Start_point(l.Start_point),End_point(l.End_point)//copy constructor
{

}

Point Line::start() const //Overloaded getter of start-point
{
	return Start_point;
}

Point Line::end() const //Overload getter of end-point
{
	return End_point;
}

void Line::start(const Point& pt) //Overload setter of start point
{
	Start_point = pt;
}

void Line::end(const Point& pt) //Overload setter of end point
{
	End_point = pt;
}

string Line::ToString() const  //return as string to describe the line. 
{
	std::string s = Shape::ToString();
	stringstream ss;
	ss <<s<< "Line Start Point: " << Start_point.ToString() << ", Line End Point: " << End_point.ToString();

	return ss.str();
}

//  Calculate length of the Line
//  Function output is length of the line
double Line::Length() const
{
	return Start_point.Distance(End_point);
}


Line& Line::operator = (const Line& source)
{
	if (this == &source)
	{
		cout << "Preclude self-assignment check worked" << endl;
		return *this;
	}
	Shape::operator=(source);
	Start_point = source.Start_point;
	End_point = source.End_point;
	//cout << "Line assignment finished" << endl;
	return *this;
}

// Overloaded Ostream << operator
ostream& operator << (ostream& os, const Line& l)
{
	os << l.ToString();
	return os;
}

void Line::Draw()  //definition of the draw function, stimulate drawing by print the context of point
{
	cout << "Draw the Line: " << ToString() << endl;
}