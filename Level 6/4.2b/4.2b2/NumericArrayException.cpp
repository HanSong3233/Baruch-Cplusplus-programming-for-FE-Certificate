// NumericArrayException.cpp
// Implementation for class NumericArrayException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
// Implements function GetMessage(), which is an abstract function in the base class. 


#include "NumericArrayException.hpp"	// Header file that contains definition for object called NumericArrayException
#include <iostream> // C++ style I/O
using namespace std;

NumericArrayException::NumericArrayException() // Default constructor
{
	m_size = 10; //Default it to be 10
}

NumericArrayException::NumericArrayException(int size) : m_size(size) {}  // Overload constructor that initializes data member m_size with function argument 

NumericArrayException::NumericArrayException(const NumericArrayException& source) :  m_size(source.m_size) {}	// Copy constructor

NumericArrayException& NumericArrayException::operator = (const NumericArrayException& source) // Assignment operator
{
	// Check to make sure not assigning to myself
	if (this == &source) return *this;

	m_size = source.m_size;// Copy state

	return *this;
}

NumericArrayException::~NumericArrayException() {}  // Destructor

std::string NumericArrayException::GetMessage() const  // Return a message string saying two arrays don't have the same size
{
	return "Two arrays don't have the same size.";
}