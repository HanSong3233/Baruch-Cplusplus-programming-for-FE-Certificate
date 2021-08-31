#ifndef PointArray_CPP
#define PointArray_CPP

#include "PointArray.hpp"//include the header file that contains the definition of PointArray 
#include "Array.hpp"//include the header file that contains the definition of Array 
#include <iostream>//C++ style I/O

PointArray::PointArray() : Array() {}  //default constructor


PointArray::PointArray(const int& size_of_array): Array(size_of_array) {}//overloaded constructor 


PointArray::PointArray(const PointArray& p_a): Array(p_a){}//copy constructor


PointArray::~PointArray(){}//destructor.


PointArray& PointArray::operator = (const PointArray& source)//overloaded assignment operator. 
{
	if (this == &source) return *this;  //check if it is a self-assignment
	else
	{
		Array::operator = (source);  //call the assignment operator in the array class. 
	}
	return *this;//return the reference.
}


double PointArray::Length()//Length() function, return the total length of point. 
{
	double SumOfPointArray = 0;

	for (int i = 0; i != (*this).Size(); i++)
	{
		if (i != ((*this).Size()) - 1) //check if it is not the last point
		{
			SumOfPointArray = SumOfPointArray + (*this)[i].Distance((*this)[i + 1]);  // Add length between points to the sum variable
		}
	}
	return SumOfPointArray;
}


#endif