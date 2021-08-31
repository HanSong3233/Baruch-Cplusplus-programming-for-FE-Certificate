//exercise 1£º test the colon syntax. 
#include "Point.hpp"		//Header file that contains definition for Point
#include "Array.hpp"		//Header file that contains definition for Array
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>  // C++ style I/O
using namespace std;

int main()
{
	Line l; 
	//before we change the line class into colon sytax, 
	//we have constructor: 4 times, destructor: 4 times, assignment: 2 times 

	//after we change the line class into colon syntax, 
	// we have constructor: 2 times, destructor 2 times. 
	//Point p;
	//Circle c;
	return 0;
}