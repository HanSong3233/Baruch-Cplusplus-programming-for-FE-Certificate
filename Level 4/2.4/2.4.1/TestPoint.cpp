//exercise 1£º adding operator to the point class. 

#include "Point.hpp"       //include the header file that contains the definition of point. 
#include "Circle.hpp"
#include "Line.hpp"
#include <iostream>      // C++ style I/O
#include <sstream>		//C++ stream buffering
#include <cmath>
using namespace std;

int main()
{
	//create two points p1 and p2.
	Point p1(1, 2);
	Point p2(3, 4);
	cout << "p1: " << p1.ToString() <<endl;
	cout << "p2: " << p2.ToString() << endl;

    //test the operator of ==.
	cout << " p1==p2? " << (p1 == p2? "Yes": "No") << endl; 

	//test the operator of -
	Point p3 = -p1;
	cout << "The result of -p1 is: " << p3.ToString() << endl;

	//test the operator of *;
	Point p4 = p1 * 3;
	cout << "The result of p1*3 is: " << p4.ToString() << endl;

	//test the opertor of +;
	Point p5 = p1 + p2;
	cout << "the result of p1+p2 is: " << p5.ToString() << endl;

	//test the operator of *+;
	p1 *= 3;
	cout << "The result of p1 *=3 is: " << p1.ToString() << endl;

	return 0;
}
