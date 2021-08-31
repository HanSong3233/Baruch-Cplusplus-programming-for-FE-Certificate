//Excercise 2: Numeric Array(Generic Inheritance).
#include "Array.cpp"// source file that contains the template array class
#include "Point.hpp"// header file that contains the definition of Point 
#include "NumericArray.hpp"//header file that contains the definition  of NumericAarry
#include "NumericArrayException.hpp"//header file that contains the definition of NumericArrayException.  
#include <iostream> // C++ style I/O
using namespace std;

//Answer for the question in the last. 
//We assume that the type should support operator + and *
//We can create an NumericArray for Point, because the support class can support these two operators.  
int main()
{
	// Declare some test variables

	NumericArray <double> DoubleNumericArray1(5);
	NumericArray <double> DoubleNumericArray2(5);

	try
	{
		// Let's initialize two numeric arrays
		for (int i = 0; i != DoubleNumericArray1.Size(); i++)
		{
			DoubleNumericArray1[i] = i;
		}

		for (int i = 0; i != DoubleNumericArray2.Size(); i++)
		{
			DoubleNumericArray2[i] = i + 1;
		}

		// Now output the result of two numeric array
		for (int i = 0; i != DoubleNumericArray1.Size(); i++)
		{
			cout << DoubleNumericArray1[i] << ", " ;
		}
		cout << endl;

		for (int i = 0; i != DoubleNumericArray2.Size(); i++)
		{
			cout << DoubleNumericArray2[i] << ", ";
		}
		cout << endl;

		// Declare sum variable
		NumericArray <double> DoubleNumericArraySum(5);

		// Now let's sum them up
		DoubleNumericArraySum = DoubleNumericArray1 + DoubleNumericArray2;

		// Verify and output
		for (int i = 0; i != DoubleNumericArraySum.Size(); i++)
		{
			cout << DoubleNumericArraySum[i] << ", ";
		}

		cout << endl;

		// Now let's calculate the DoubleNumericArraySum *2;
		NumericArray <double> doubleNumericArrayScale(5);
		doubleNumericArrayScale = DoubleNumericArraySum * 2;

		// Now let's output the result
		for (int i = 0; i != doubleNumericArrayScale.Size(); i++)
		{
			cout << doubleNumericArrayScale[i] << ", ";
		}
		cout << endl;

		// Now let's calculate the dot product of 
		cout << "The Dot Product of two array equals: " << (DoubleNumericArray1.DotProduct(DoubleNumericArray2)) << endl;

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