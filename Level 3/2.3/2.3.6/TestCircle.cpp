//Exercise 6£º create a circle class, which has a center point and radius. 
#include <iostream>
#include <sstream>
#include "Circle.hpp"
#include "Point.hpp"

using namespace std;

int main()
{
	double x, y, x1, y1, a, b;  // the center point will be (x,y) and the radius will be a. 
	                 //then we will reset the circle, center point will be (x1,y1), radius will be b.

	//request user to enter the a, y value of centrepoint.
	cout << "Now we will construct a circle. "<<endl;
	cout << "Please enter the x axis of your center point: ";
	cin >> x;
	cout << "Please enter the y axis of your center point: ";
	cin >> y;

	Point p1(x, y);//construct the point x,y

	//Request user to enter the radius of Circle, a, here.
	cout << "Please enter the radius of circle, a, here: ";
	cin >> a;

	//construct the point of 
	Circle c(p1, a);

	//output the result of circle   
	cout << "The circle ,c, we create is: " << c.ToString() << endl;
	cout << "The centre point of c is: " << c.CentrePoint().ToString() << endl;
	cout << "The radius of the circle we create is: " << c.Radius() << endl;
	cout << "The diameter of the circle, c, is£º " << c.Diameter() << endl;
	cout << "The circumstance of the circle, c, is£º " << c.Circumference() << endl;
	cout << "The area of the circle, c, is£º " << c.Area() << endl;

	//now we request user to reset the center point of the circle
	cout << endl<<"Now please reset the circle."<<endl;
	cout << "Please reset the x axis of your center point: ";
	cin >> x1;
	cout << "Please enter the y axis of your center point: ";
	cin >> y1;	

	Point p2(x1, y1);//constrcut the new center point. 
	c.CentrePoint(p2);  //reset the center point. 
	
	//now we request user to reset the center point of the circle
	cout << "Please reset the radius of the circle: ";
	cin >> b;
	c.Radius(b);  //reset the center point.

    //output the result of circle after we reset.  
	cout << "After we reset the center point and radius: ";
	cout << "The circle is: " << c.ToString() << endl;
	cout << "The centre point of the circle is: " << c.CentrePoint().ToString() << endl;
	cout << "The radius of the circle is: " << c.Radius() << endl;
	cout << "The diameter of the circle, c, is£º " << c.Diameter() << endl;
	cout << "The circumstance of the circle, c, is£º " << c.Circumference() << endl;
	cout << "The area of the circle, c, is£º " << c.Area() << endl;
		
	return 0;
}