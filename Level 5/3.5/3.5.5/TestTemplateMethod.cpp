//Exercise 5£ºTest template method
//add a print function to the shape class. In this function, call the Tostring() and send the result to the cout object. 

#include "Point.hpp"		//Header file that contains definition for Point
#include "Array.hpp"		//Header file that contains definition for Array
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>  // C++ style I/O
using namespace std;

class A
{
public:
	virtual std::string F() { return "A"; }
};

class B : public A
{
public:
	std::string F() { return "B"; }
};

int main()
{
	A a; B b;
	A* ap;

	std::cout << a.F() << ", ";
	std::cout << b.F() << ", ";

	ap = &a; std::cout << ap->F() << ", ";
	ap = &b; std::cout << ap->F() << std::endl;

	return 0;
}