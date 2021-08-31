#include <iostream>
#include <sstream>
#include "StackEmptyException.hpp"
#include "StackException.hpp"
using namespace std;

//class StackEmptyException
//Contains defalut constructor, copy constructor, destructor, and assignment operator.

StackEmptyException::StackEmptyException() {}//default constructor

StackEmptyException::StackEmptyException(const StackEmptyException &source) {}//copy constructor

StackEmptyException& StackEmptyException::operator = (const StackEmptyException &source) { return *this; }//overloaded assignment operator

StackEmptyException::~StackEmptyException() {};//destructor