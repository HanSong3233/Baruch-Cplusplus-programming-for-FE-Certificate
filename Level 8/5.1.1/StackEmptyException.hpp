#ifndef StackEmptyException_HPP
#define StackEmptyException_HPP
#include "StackException.hpp"
#include <iostream>
#include <sstream>
using namespace std;

// class StackFullException is a derived class of class StackException
// Contains standard constructor, copy constructor, destructor, and assignment operator
class StackEmptyException : public StackException
{
private:

public:
	StackEmptyException();//default constrcutor

	StackEmptyException(const StackEmptyException &source);//copy constructor

	virtual ~StackEmptyException();  //destructor
	StackEmptyException& operator=(const StackEmptyException &source); //assignment operator.

};

#endif

