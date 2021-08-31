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

//constructor and destructor
public:
	Point();//constructor 
	~Point();//destructor

	//access functions
	double GetX(); //access X
	double GetY(); //access Y
    string ToString();//returns a string description of the point. 

	//Modifier
	void SetX(double new_X);
	void SetY(double new_Y);
};
#endif
