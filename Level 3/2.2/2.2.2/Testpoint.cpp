#include "Point.hpp"//include the header file 
#include <iostream>//C++ style I/O
using namespace std;

int main() 
{
	double x, y, x2,y2;//x and y is the x,y value of point p1.  x2,y2 is the x, y value of point p2.

	//request user to enter the value of x and y for p1. 
	cout << "Please enter the x of your point here: ";
	cin >> x;
	cout << "Please enter the y of your point here: ";
	cin >> y;
	
	//create a point object p1
	Point p1;
	cout << "Now we name this point as p1" << endl;

	//set the coordinates enter by the user
	p1.SetX(x);
	p1.SetY(y);
	
	//Print the description of the Point use Tostring Function
	cout << "The point your created, p1, is:" << p1.ToString() << endl;
	
	//print the distance of point p1 to origin. 
	cout << "The distance between p1 and origin is: " << p1.DistanceOrigin() << endl;

	//request user to enter the value of x and y coordinate for p2. 
	cout << "Please enter the x of another point you want to create here: ";
	cin >> x2;
	cout << "Please enter the y of another point here: ";
	cin >> y2;
	
	//create a point object p2
	Point p2;
	cout << "Now we name this point as p2"<<endl;
	
	//set the coordinates enter by the user
	p2.SetX(x2);
	p2.SetY(y2);
	
	//Print the description of the Point use Tostring Function
	cout << "Another point your created, p2, is:" << p2.ToString() << endl;
	cout << "The distance between p1 and p2 is: " << p1.Distance(p2) << endl;

	return 0;
}