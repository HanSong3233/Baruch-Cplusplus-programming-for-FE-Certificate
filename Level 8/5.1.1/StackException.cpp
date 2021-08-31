#include <iostream>
#include <sstream>
#include "StackException.hpp"
using namespace std;

//class StackException
//Contains defalut constructor, copy constructor, destructor, and assignment operator.

StackException::StackException() {}//default constructor

StackException::StackException(const StackException &source) {}//copy constructor

StackException& StackException::operator = (const StackException &source) { return *this; }//overloaded assignment operator

StackException::~StackException() {};//destructor