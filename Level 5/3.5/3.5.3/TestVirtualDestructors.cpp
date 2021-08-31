//Exercise 3£ºTest Virtual Destructors.

#include "Point.hpp"		//Header file that contains definition for Point
#include "Array.hpp"		//Header file that contains definition for Array
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>  // C++ style I/O
using namespace std;

int main()
{
	Shape* shapes[3];  // Create some Shape* pointers and assign them to a Shape, Point, and Line objects
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++) delete shapes[i];  // Now delete each of them


	//When we do not make the destructor virtual, The proper destructors will NOT be called.
	//only shape destructors were called 3 times. 

	//After declaring the base class destructor as virtual, 
	//the proper destructors for the derived classes are now called.	
	//shape destructor was called 5 times, point destructor was called 3 times, line destrcutor was called once. 
				                                    
	return 0;
}

