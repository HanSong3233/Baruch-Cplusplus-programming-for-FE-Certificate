//Exercise 7: use incline function in the setter and getter of the point class. 
#include "Point.hpp"
#include <iostream>
using namespace std;

int main() 
{
	double x, y, x2,y2;//x and y is the x,y value of point p1.  x2,y2 is the x, y value of point p2.

	//request user to enter the value of x and y for p1. 
	cout << "Please enter the x of your point here: ";
	cin >> x;
	cout << "Please enter the y of your point here: ";
	cin >> y;
	
	//create a point object p1, set the x,y value enter by the user. 
	Point p1(x,y);
	cout << "Now we name this point as p1" << endl;
	
	//Print the description of the Point use Tostring Function
	cout << "The point your created, p1, is:" << p1.ToString() << endl;
	cout << "The x value of p1, is: " << p1.X() << endl;
	cout << "The y value of p1, is: " << p1.Y() << endl;

	//request user to reset the value of x and y for p1. 
	cout << endl<<"Now we reset the point." << endl;
	cout << "Please reset the x of p1 here: ";
	cin >> x2;
	cout << "Please enter the y of p1 here: ";
	cin >> y2;

	//reset the value of x and y of p1.
	p1.X(x2);
	p1.Y(y2);

	//Print the description of the Point after reset.
	cout << "The point p1, after resetting, is:" << p1.ToString() << endl;
	cout << "The x value of p1, after resetting, is: " << p1.X() << endl;
	cout << "The y value of p1, after resetting, is: " << p1.Y() << endl;

	return 0;
}