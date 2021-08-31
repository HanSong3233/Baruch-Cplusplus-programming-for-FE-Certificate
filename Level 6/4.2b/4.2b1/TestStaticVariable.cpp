//Excercise 1: Static variable for Array Default Size
#include "Array.cpp"// source file that include the template array class
#include "Point.hpp"// header file that inlcude the definition of Point 
#include <iostream> // C++ style I/O
using namespace std;



int main()
{
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;

	cout << intArray1.GetDefaultSize() << endl;
	cout << intArray2.GetDefaultSize() << endl;
	cout << doubleArray.GetDefaultSize() << endl;

	intArray1.DefaultSize(15);

	cout << intArray1.GetDefaultSize() << endl;
	cout << intArray2.GetDefaultSize() << endl;
	cout << doubleArray.GetDefaultSize() << endl;

	return 0;
}

	/*
	result:
	10
	10
	10
	15
	15
	10
	*/

	/*
	a static member variable is created for each different type of template class that is created. 
	 Therefore, the default size for doubleArray will remain as 10 when we change the default-size of intArray.
	*/

