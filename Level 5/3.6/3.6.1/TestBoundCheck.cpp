//Exercise 1£ºBound checking Array.
//throw -1 if index is too small or too big. access the element that does not exists.
//catch the exceptio and print an error message. 

#include "Point.hpp"		//Header file that contains definition for Point
#include "Array.hpp"		//Header file that contains definition for Array
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>  // C++ style I/O
using namespace std;

int main()
{
	Array array(3); // Initialize an array with size of 3

	// Let's try the SetElement().
	try
	{
		array.SetElement(Point(1, 1), 0); // This should be OK, no error/
		array.SetElement(Point(2, 2), -1); // This should throw an error
	}
	catch (int err)  // Catch for int exceptions
	{
		if (err == -1) cout << "Array out of bounds error!" << endl;
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}
	
	// Let's try the GetElement() function..
	try
	{
		cout << array.GetElement(-1); // Should throw an error
	}
	catch (int err)  // Catch for int exceptions
	{
		if (err == -1) cout << "Array out of bounds error!" << endl;
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}
	
	// Let's try the [] operator.
	try
	{
		array[0] = Point(1, 1); // Should be fine
		array[-1] = Point(2, 2); // Should throw an error
	}
	catch (int err)  // Catch for int exceptions
	{
		if (err == -1) cout << "Array out of bounds error!" << endl;
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}


	return 0;
}

