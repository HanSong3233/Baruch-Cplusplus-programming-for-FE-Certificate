//Excercise 4: Stack class
#include "Array.hpp"// source file that include the template array class
#include "Point.hpp"// header file that inlcude the definition of Point 
#include "PointArray.hpp"//header file that include the definition of PointArray
#include "Stack.hpp"
#include <iostream> // C++ style I/O
using namespace std;


int main()
{
	// Initialize a stack of int of length 3, s1.
	Stack<int> s1(3);

	try
	{
		// Push some objects of type int into s1
		s1.Push(1);
		s1.Push(2);
		s1.Push(3);

		s1.Push(4);	// This should error, asthe size of array is only 3. 
	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		std::cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		std::cout << "An unhandled exception has occurred" << endl;
	}

	try
	{
		// Pop out 3, 2, 1 from s1
		cout << s1.Pop() << endl;
		cout << s1.Pop() << endl;
		cout << s1.Pop() << endl;

		cout << s1.Pop() << endl; // This should error, since there are no longer any items in the stack.
								  
	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}



	try
	{
		s1.Push(1);
		cout << s1.Pop() << endl;  //test if the current position stay unchange when Pop() fails to implement	                            //this should be fine, as we have add one more element. 

	}
	catch (ArrayException& arr_ex)  // Catch for an array exception
	{
		cout << arr_ex.GetMessage() << endl;  // Output message generated from derived class of ArrayException
	}
	catch (...)  // If not catch match is found default catch is called
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	return 0;
}