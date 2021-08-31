 //Exercise 4£ºConst function create a const point and try to set the x-coordinate. 
//it should return a compile error

#include "Point.hpp"
#include <iostream>
using namespace std;



int main() 
{
	const Point cp(1.5, 3.9); //we set cp as a constant point, (1.5,3.9)
	//cp.X(0.3);  //We try to change the x axis to 0.3 using X(), but it leads to a compiler error!
	
	cout << "We construct a constant point (1.5,3.9)" << endl;
	cout << "We try to change the x axis to 0.3 using X(), but it leads to a compiler error!" << endl<<endl;
	
	//we find that changing a constant object will lead vto complier error	
	//cout<<cp.X()<<endl;   we find this do not work either before we change the function to const function.
	//after we change function into const. 
	cout << "we make functions into const" << endl;
	cout << "The constant point is: " << cp.ToString()<<endl;
	cout << "The value of this constant point on x_axis is: " << cp.X() << endl;
	cout << "The value of this constant point on x_axis is: " << cp.Y() << endl;
	cout << "The distance of this constant point to origin is: " << cp.Distance()<<endl;
	Point c(1, 1);
}