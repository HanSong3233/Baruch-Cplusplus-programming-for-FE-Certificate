//Excception.hpp define two classes of Exception, 
#ifndef StackFullException_HPP
#define StackFullException_HPP
#include "StackException.hpp"
#include <iostream>
#include <sstream>
using namespace std;

// class StackFullException is a derived class of class StackException
// Contains standard constructor, copy constructor, destructor, and assignment operator
class StackFullException : public StackException
{
private:

public:
	StackFullException();//default constrcutor

	StackFullException(const StackFullException &source);//copy constructor

	virtual ~StackFullException();  //destructor
	StackFullException& operator=(const StackFullException &source); //assignment operator.

};

#endif
