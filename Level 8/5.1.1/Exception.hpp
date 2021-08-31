//Excception.hpp define two classes of Exception, 
//one is Array Exception, The other is OutofBoundException.
#ifndef Exception_HPP
#define Exception_HPP
#include <iostream>
#include <sstream>
using namespace std;

// class ArrayException is an abstract base class that contains a pure virtual function - GetMessage().
// contains standard constructor, copy constructor, destructor, and assignment operator.
class ArrayException
{
private:
	//No object here¡£
public:
	ArrayException();  //defalut constructor
	ArrayException(const ArrayException &source);  //copy constrcutor
	ArrayException& operator = (const ArrayException &source);  //assignment operator.

	virtual ~ArrayException(); //destructor
	virtual string GetMessage() const=0;  //function: GetMessage

};


// class OutOfBoundsException is a derived class of class ArrayException
// Contains standard constructor, overloaded constructor, copy constructor, destructor, and assignment operator
class OutOfBoundException: public ArrayException
{
private:
	int m_index;
public:
	OutOfBoundException();//default constrcutor
	OutOfBoundException(int num);//constructor with number.
	OutOfBoundException(const OutOfBoundException &source);//copy constructor

	virtual ~OutOfBoundException();  //destructor
	OutOfBoundException& operator=(const OutOfBoundException &source); //assignment operator.
	virtual string GetMessage() const;
};

#endif


