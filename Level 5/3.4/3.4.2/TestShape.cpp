//exercise 2£º creating shape base class.  
#include "Point.hpp"		//Header file that contains definition for Point
#include "Array.hpp"		//Header file that contains definition for Array
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>  // C++ style I/O
using namespace std;

int main()
{
	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	Line l(Point(1, 2), Point(3, 4)); // Create line.

	cout << s.ToString() << endl; // Print shape.   //ID:41
	cout << p.ToString() << endl; // Print point.   //(10,20)
	cout << l.ToString() << endl; // Print line     //Line Start Point(1,2) Line End Point (10,20) 

	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.                     //Shape ID: 41
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work?     //Point ID 18467, it works 

	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?       //Line ID: 19169


	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible?    It is possible, actually.
	cout << sp->ToString() << endl; // What is printed?  //ID: 18467 (the ID of the point p actually)

	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call the base class assignment in point?
	                                       //(10,20) 18467

	//the ID will not be copied if I do not call the nase class assignment. 
	return 0;
}

