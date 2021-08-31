#ifndef PointArray_HPP
#define PointArray_HPP
#include "Array.hpp"
#include "Point.hpp"
#include <iostream>
#include <sstream>
using namespace std;

class PointArray : public Array<Point>  //Template argument for Array is fixed to type Point (concrete inheritance)
{
private:
	//no member data here

public:
	//constructor and destructor
	PointArray();   //default constructor
	PointArray(const int& size_of_array);   //overloaded constructor with the size of array as input. 
	PointArray(const PointArray& p_a);     //copy constructor

	~PointArray();//destrcutor. 

	//overloaded assignment operators.
	PointArray& operator = (const PointArray& source);
	
	//Getter function
	double Length();  //define the length function, returns the total length between points. 

};


#endif
