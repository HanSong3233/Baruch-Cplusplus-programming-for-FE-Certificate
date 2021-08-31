//Exercise 4: friends 
// move the << operator inside the class definition and declare them as friends

#include "Point.hpp"       //include the header file that contains the definition of point. 
#include "Circle.hpp"
#include "Line.hpp"
#include <iostream>      // C++ style I/O
#include <sstream>		//C++ stream buffering
#include <cmath>
using namespace std;

int main()
{
	//create two point p1,p2
	Point p1(1, 2);
	Point p2(3, 4);
	//in order to chech << operator in Point class, print the two points p1,p2. 
	cout << "point p1: " << p1 <<endl;
	cout << "point p2: " << p2<< endl;

	//create a line with two points p1,p2
	Line l(p1, p2);
	//in order to check << operator in Line class, orint the line l.
	cout << "line l: " << l << endl;
   
	return 0;
}
