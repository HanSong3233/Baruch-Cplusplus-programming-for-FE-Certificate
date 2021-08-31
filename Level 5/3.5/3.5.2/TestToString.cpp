//Exercise 2£º Calling Base class Functionality.
//incorpoarte the ID from the shape base class with Totring function in Point Line and Circle class. 

#include "Point.hpp"		//Header file that contains definition for Point
#include "Array.hpp"		//Header file that contains definition for Array
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>  // C++ style I/O
using namespace std;

int main()
{
	// Let's create 2 Point objects 
	Point p_1(1, 1);
	Point p_2(2, 2);

	//Let's create a Line object
	Line l(p_1, p_2);
	// Let's create some circle objects 
	Circle c_1(p_1, 1);

    cout << p_1.ToString() << endl; // Print ID and then point.
	cout << c_1.ToString() << endl; // Print ID and then Circle
	cout << l.ToString() << endl; // Print ID and then line

	//we find that ID printed when priniting a point or line. 
	return 0;
}

