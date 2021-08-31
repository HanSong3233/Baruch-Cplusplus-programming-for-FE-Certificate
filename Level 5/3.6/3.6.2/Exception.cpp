#include <iostream>
#include <sstream>
#include "Exception.hpp"
using namespace std;

//class ArrayException
//Contains defalut constructor, copy constructor, destructor, and assignment operator.

ArrayException::ArrayException() {}//default constructor

ArrayException::ArrayException(const ArrayException &source) {}//copy constructor

ArrayException& ArrayException::operator = (const ArrayException &source) { return *this; }//overloaded assignment operator

ArrayException::~ArrayException(){};//destructor


//class OutofBound: Derived class of class ArrayException
//Contains default constructor, overloaded constructor, copy constructor, destructor, and assignment operator.
//Implements function GetMessage(), which is an abstract function in the base class.

OutOfBoundException::OutOfBoundException():ArrayException()  //default constructor
{
	m_index = 0;     //assign the m_index to zero
}

OutOfBoundException::OutOfBoundException(int num): ArrayException()  //overloaded constructor
{

	m_index = num;   //assign the m_index to num. 
}

OutOfBoundException::OutOfBoundException(const OutOfBoundException &source) //copy constructor
{
	
	ArrayException::operator= (source);//generator ArrayException
	m_index = source.m_index;//copy the state of m_index
}


OutOfBoundException& OutOfBoundException::operator = (const OutOfBoundException& source) // Assignment operator
{
	// Check to make sure not assigning to myself
	if (this == &source) return *this;

	// Call ArrayException assignment
	ArrayException::operator= (source);

	// Copy the state of m_index
	m_index = source.m_index;

	return *this;
}

OutOfBoundException::~OutOfBoundException() {}  // Destructor

string OutOfBoundException::GetMessage() const  // Return a message string saying the index is out of bounds
{
	stringstream ss;
	ss<< "The index "<< m_index<<" is out of bounds.";
	return ss.str();
}



