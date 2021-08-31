//Exercise 2£ºException object
//create an exception hierarchy with ArrayException base class and OutOfBoundException derived class
#include "Point.hpp"		//Header file that contains definition for Point
#include "Array.hpp"		//Header file that contains definition for Array
#include "Line.hpp"
#include "Circle.hpp"
#include "Exception.hpp"
#include <iostream>  // C++ style I/O
using namespace std;

int main()
{
	Array array(3); // Initialize an array with size of 3

	// Let's try the SetElement().
	try
	{
		array.SetElement(Point(1, 1), 1); // This should be OK, no error
		array.SetElement(Point(2, 2), 0); // This should throw an error
		cout << array.GetElement(1)<<endl;
		array.SetElement(Point(1, 1), -1); // This should be OK, no error
	}
	catch (ArrayException& arr_ex)  // Catch for array exceptions, arr_ex means array exception. 
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	// Let's try the GetElement() function..
	try
	{
		array.GetElement(4); // Should throw an error
	}
	catch (ArrayException& arr_ex)  // Catch for array exceptions
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	// Let's try the [] operator.
	try
	{
		array[0] = Point(1, 1); // Should be fine
		array[-3] = Point(2, 2); // Should throw an error
	}
	catch (ArrayException& arr_ex)  // Catch for array exceptions
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}


	return 0;
}



