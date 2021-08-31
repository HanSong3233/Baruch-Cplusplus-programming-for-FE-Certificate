//Exercise 5: create the line class that has a start point and end point. 

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"

using namespace std;

int main() 
{
	double x_1, y_1, x_2, y_2,x_3,y_3,x_4,y_4; //for initialization the start point is (x1,y1), the end point is (x2,y2)
	                                           //after we make change, the start point is (x3,y3), the end point is (x4,y4)
	
	//reuqest user to enter the x,y value of two points.  
	cout << "Now let's create a line with 2 points"<<endl;
    cout << "Please enter the x value of start point: ";
	cin >> x_1;
	cout << "Please enter the y value of start point: " ;
	cin >> y_1;

	//construct the start point. 
	Point p1(x_1, y_1);

	cout << "Please enter the x value of end point: ";
	cin >> x_2;
	cout << "Please enter the y value of end point: ";
	cin >> y_2;

	//construct end points
	Point p2(x_2, y_2);
	
	//construct the line with two points
	Line line_1(p1, p2); //line_1 is the line we create

	//print the information of line we initialize.
	cout << "The line we create is: " << line_1.ToString() << endl;   //print the line we create
	cout << "The start point of the line is " << line_1.start().ToString() << endl; //print the start point of the line
	cout << "The end point of the line is " << line_1.end().ToString() << endl; //print the end point of the line
	cout << "The length of we line we create is: " << line_1.Length() << endl<< endl;//print the length of the line. 

	//now we change the line by changing the start point and end point.
	cout << "Now let's change our start point and end point of the line." << endl;
	cout << "Please enter the x value of the new start point: ";
	cin >> x_3;
	cout << "Please enter the y value of the new start point: ";
	cin >> y_3;

	cout << "Please enter the x value of end point: ";
	cin >> x_4;
	cout << "Please enter the y value of end point: ";
	cin >> y_4;

	//construct the new point for the line.  
	Point p3(x_3, y_3);
	Point p4(x_4, y_4);

	//set the start point and end point
	line_1.start(p3);
	line_1.end(p4);

	//print the information of line after we set the start point and end point.
	//print the information of line we initialize.
	cout << "The new line is: " << line_1.ToString() << endl;   //print the line we create
	cout << "The start point of the new line is: " << line_1.start().ToString() << endl;//print the start point of the line
	cout << "The end point of the new line is: " << line_1.end().ToString() << endl;//print the end point of the line
	cout << "The length of the new line is: " << line_1.Length() << endl;//print the length of the line.

	return 0;
}
