#ifndef NumericArray_HPP
#define NumericArray_HPP

#include "Array.hpp"
#include <iostream>
#include <sstream>
using namespace std;

template <class T> class NumericArray : public Array<T>
{
private:
	//No element needed
public:
	//constructors and destructors
	NumericArray();  //default constructor
	NumericArray(const int& size_array);  //overloaded constrcutor
	NumericArray(const NumericArray &a);  //copy constructor
	virtual ~NumericArray();

	//overload operators
	NumericArray<T> &operator = (const NumericArray<T> &source);        //assignment operator
	NumericArray<T> operator + (const NumericArray<T> &source);  //Add the element of two Numeric Array
	NumericArray<T> operator * (const T num);                          //scale the element of numeric Array

	double DotProduct(const NumericArray<T>& na);  // Calculates the dot product
};


#ifndef NumericArray_CPP
#include "NumericArray.cpp"
#endif // NumericArray_CPP

#endif
