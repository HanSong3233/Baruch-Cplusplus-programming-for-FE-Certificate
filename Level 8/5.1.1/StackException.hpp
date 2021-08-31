//Excception.hpp define two classes of Exception, 
//one is Array Exception, The other is OutofBoundException.
#ifndef StackException_HPP
#define StackException_HPP
#include <iostream>
#include <sstream>
using namespace std;

// class ArrayException is an abstract base class that contains a pure virtual function - GetMessage().
// contains standard constructor, copy constructor, destructor, and assignment operator.
class StackException
{
private:
	//No object here¡£
public:
	StackException();  //defalut constructor
	StackException(const StackException &source);  //copy constrcutor
	StackException& operator = (const StackException &source);  //assignment operator.

	virtual ~StackException(); //destructor

};

#endif
