#include <iostream>
#include <sstream>
#include "StackFullException.hpp"
#include "StackException.hpp"
using namespace std;

//class StackFullException
//Contains defalut constructor, copy constructor, destructor, and assignment operator.

StackFullException::StackFullException() {}//default constructor

StackFullException::StackFullException(const StackFullException &source) {}//copy constructor

StackFullException& StackFullException::operator = (const StackFullException &source) { return *this; }//overloaded assignment operator

StackFullException::~StackFullException() {};//destructor