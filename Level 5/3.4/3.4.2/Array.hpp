//array.hpp a header file that construct a class of array.
//with the functionality size() GetElement() SetElement(), overloaded operators: = []. 
#ifndef Array_HPP
#define Array_HPP
#include "Point.hpp"
#include <iostream>
#include <sstream>
using namespace std;

class Array
{
private:
	//Member data:1.Point objects 2. the size of the array
	Point* m_data;			// Dynamic C array of Point objects
	int m_size;				// Size of the array

public:
	// Constructors
	Array();											// Default constructor
	Array(const int& size_of_array);					// constructors with size given.
	Array(const Array& a);								// Copy constructor
	Array& operator = (const Array& a);			// Assignment operator
	Point& operator [] (int index);						// Square bracket operator. Return reference so the [] operator can be used for both reading and writing elements
	const Point& operator [] (int index) const;			// Square bracket operator - CONST version.
	~Array();											// Destructor

	// Accessing functions for obtaining element and the size of the array				
	int Size() const;										// The size of the array
	Point& GetElement(int pt_index) const;					// Get element by reference based on index number

	// Setter functions
	void SetElement(const Point& pt, int pt_index);	// Sets an element based on index number
};

#endif // Array_HPP
