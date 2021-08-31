//Point.hpp a header file that construct a class of point.
//with the functionality GetX(),GetY(),SetX(),SetY();ToString(). 

#ifndef Point_HPP
#define Point_HPP

#include <iostream>  //C++ style I/O
#include <sstream>	//C++ stream buffering
using namespace std;

class Point
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
	double X(); //access X£¬we rename it from Get_X to X
	double Y(); //access Y, we rename it from Get_Y to Y
    string ToString();//returns a string description of the point. 
	double Distance();//Calculate the distance of point to origin, we rename it from DistanceOrgin to Distance
	double Distance(const Point& p) const;

	//Modifier
	void X(double new_X);//set the value of X, we rename it from SetX to X 
	void Y(double new_Y);//set the value of Y, we rename it from SetY to Y.
};
#endif
