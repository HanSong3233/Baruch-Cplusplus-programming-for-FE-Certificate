//Exercise 2: dynamic creating object: create points using three constructors and create an array of points.  
#include "Point.hpp"       //include the header file that contains the definition of point. 
#include "Circle.hpp"
#include "Line.hpp"
#include <iostream>      // C++ style I/O
#include <sstream>		//C++ stream buffering
#include <cmath>
using namespace std;

int main()
{
	int size_of_array = 3;  //here we make the size of array to 3.

	Point** pp = new Point*[size_of_array];  //create an array of three pointers. each contain a point


	for (int i = 0; i < size_of_array; i++)
	{
		pp[i] = new Point(i, i);  // Create for each element in the array a point on the heap, and use constructors with x,y coordinates.
	}										// assign the three lement as (1,1), (2,2),(3,3) 

									
	for (int i = 0; i < size_of_array; i++)
	{
		cout << *pp[i] << endl;
	}

	// Iterate the array again and delete each points.
	for (int i = 0; i < size_of_array; i++)
	{
		delete pp[i];
	}

	delete[] pp; // now delete the array itself

	return 0;
}


