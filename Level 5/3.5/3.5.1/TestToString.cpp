//Exercise 1£º Polymorphic Tostring  
#include "Point.hpp"		//Header file that contains definition for Point
#include "Array.hpp"		//Header file that contains definition for Array
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>  // C++ style I/O
using namespace std;

int main()
{
	Point p(1, 1);
	Shape* shape_1 = &p;
	cout << shape_1->ToString() << endl;
	return 0;
	//when we do not declare the Tostring function as virtual, the function in shape was class,
	//the result printed is ¡°ID£º41¡±

	//when we  declare the Tostring function as virtual, the Tostring function in Point is called. 
	//the result printed is: "(1,1)"

}

