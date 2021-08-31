//Point.hpp a header file that construct a class of point.
//with the functionality GetX(),GetY(),SetX(),SetY();ToString(). 

#ifndef Point_HPP
#define Point_HPP
#include <iostream>  //C++ style I/O
#include <sstream>	//C++ stream buffering
#include "Shape.hpp"
using namespace std;

class Point: public Shape
{
private:
	double m_x;  //the value of point on X coordinate
	double m_y;  //the value of point on Y coordinate


public:
    //constructor and destructor
	Point();//constructor 
	Point(double x, double y);//constructor with initial value.
	Point(const Point& p);// copy constructor. 
	~Point();//destructor

	//access functions
	double X() const; //access X
	double Y() const; //access Y
    string ToString() const;//returns a string description of the point. 
	double Distance() const;//Calculate the distance of point to origin, we rename it from DistanceOrgin to Distance
	double Distance(const Point& p) const;
	void Draw();

	//Modifier
	void X(double new_X);//set the value of X.
	void Y(double new_Y);//set the value of Y.


	//operator overloading
	Point operator - () const;             // Negate the cordinates
	Point operator * (double factor) const;//scale the coordinates
	Point operator + (const Point& p) const;//Add coordinates
	bool operator ==(const Point &p) const;//Equally compare operator
	Point& operator = (const Point& source);//assignment operator
	Point& operator *= (double factor);//scale the coordinate and assign. 
	

														
};

//Overloaded Ostream << operator
ostream& operator << (ostream& os, const Point& p); //send to ostream

#endif

