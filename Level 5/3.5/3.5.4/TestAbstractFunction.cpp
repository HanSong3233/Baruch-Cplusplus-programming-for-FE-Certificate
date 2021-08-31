//Exercise 4£ºAbstract Functions.
//Create a pure abstract function Draw() in shape base class and override it in Circle, Line, Point. 

#include "Point.hpp"		//Header file that contains definition for Point
#include "Array.hpp"		//Header file that contains definition for Array
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>  // C++ style I/O
using namespace std;

int main()
{
	Shape* shapes[5];
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Point(1, 2);
	shapes[3] = new Circle;
	shapes[4] = new Line(Point(1,2), Point(3,4));
	for (int i = 0; i < 5; i++) shapes[i]->Draw();  //Call the Draw() functions implemented in each of the derived classes
	for (int i = 0; i < 5; i++) delete shapes[i];  //Now delete all of the objects

    //Shape s; // we can't create a instance of Shape as shape is an abstract class now. 

	return 0;
}


