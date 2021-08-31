//Exercise 1£º construct a point class. 

#include "Point.hpp"//include the header file 
#include <iostream>//C++ style i/O
using namespace std;

int main() 
{
	double x, y;

	//request user to enter the value of x and y
	cout << "Please enter the x here: ";
	cin >> x;
	cout << "Please enter the y here: ";
	cin >> y;
	//create a point object p1
	Point p1;
	//set the coordinates enter by the user
	p1.SetX(x);
	p1.SetY(y);
	//Print the description of the Point use Tostring Function
	cout << "The point is " << p1.ToString() << endl;
	//Print the point coordinates using the get function. 
	cout << "The point x coordinate is " << p1.GetX() << endl;
	cout << "The point x coordinate is " << p1.GetX() << endl;

	return 0;
}