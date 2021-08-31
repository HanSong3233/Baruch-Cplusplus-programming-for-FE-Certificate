//Exercise 1: dynamic creating object: create points using three constructors and create an array of points.  

#include "Point.hpp"       //include the header file that contains the definition of point. 
#include "Circle.hpp"
#include "Line.hpp"
#include <iostream>      // C++ style I/O
#include <sstream>		//C++ stream buffering
#include <cmath>
using namespace std;

int main()
{
	// Create some Point objects on the heap and then std::cout them just to verify they were created

	Point* pt_1 = new Point;  // Using default constructor					
	cout << *pt_1 << endl;

	Point* pt_2 = new Point(1, 1);  // Using constructor with coordinates 
	cout << *pt_2 << endl;

	Point* pt_3 = new Point(*pt_1);  // Using copy constructor 
	cout << *pt_3 << endl;

	// Let's calculate distance and pass to std::cout
	cout << "Distance is: " << (*pt_2).Distance(*pt_3) << endl;

	//delete all of the three points
	delete pt_1;
	delete pt_2;
	delete pt_3;

	//Then let's create an array of points.
	int size_of_array;
	cout << "enter the size of input: ";
	cin >> size_of_array;

	//Point array_point[size_of_array];         error, it must have a constant size of values  
	Point* pp = new Point[size_of_array];   //create a array of size  

	for (int i = 0; i < size_of_array; i++)    //use the constructor with x,y coordinates, making every element (1,1)
	{
		pp[i]=Point(1,1);
	}

	for (int i = 0; i < size_of_array; i++)   //print all the points in the array
	{
		cout << pp[i] << endl;
	}

	delete[] pp;  //delete the pp array

	return 0;
}
