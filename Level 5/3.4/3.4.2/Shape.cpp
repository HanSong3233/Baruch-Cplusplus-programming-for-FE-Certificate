#include <iostream>
#include <sstream>
#include "stdlib.h"
#include "shape.hpp"
using namespace std;

Shape::Shape() //default constructor 
{
	m_id = rand();
}

Shape::Shape(const Shape &s) : m_id(s.m_id)  //copy constructor
{
}

Shape::~Shape()  //destructor
{
}

//overloaded assignment operators
Shape& Shape::operator = (const Shape& s) 
{
	//check to make sure not assigning to myself
	if (this == &s) return *this;

	// Copy state
	m_id = s.m_id;
	return *this;
}

//return the id of the shape
int Shape::ID() const
{
	return m_id;
}

// Returns string description of the shape
string Shape::ToString() const
{
	stringstream ss;
	ss << "ID:" << m_id;

	return ss.str();
}