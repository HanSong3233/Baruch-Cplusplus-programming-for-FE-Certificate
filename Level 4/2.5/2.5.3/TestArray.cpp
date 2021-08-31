//exercise 3: create a array class to manage memory. data member: Point* m_data, m_size as int
//with constructors, destructors, assignment operators, square bracket operators. 
//with funtion size(), SetElement(),GetElement().

#include "Point.hpp"		//Header file that contains definition for Point
#include "Array.hpp"		//Header file that contains definition for Array
#include <iostream>  // C++ style I/O
using namespace std;

int main()
{
	// Create some Point objects on the stack
	Point pt_1(1, 2);
	Point pt_2(3, 4);
	Point pt_3(5, 6);

	Array array(4); // Initialize array object with size of 4

	// Now let's add the Point objects to the array using SetElement
	array.SetElement(pt_1, 0);
	array.SetElement(pt_2, 1);
    //write the array[3] by [] operator to test it.
	array[3] = pt_3;
	array.SetElement(Point(7, 8), 2);


	//print the content of array, check if the GetElement works
	cout << "The content of array is: ";
	for (int i = 0; i < array.Size(); i++)
	{
		cout << array.GetElement(i);
	}
	cout << endl;
	//let's try the GetElement when index out of bound. 
	cout << "let's try the GetElement() when index out of bound" << endl;
	cout << array.GetElement(10) << endl;

	//let's try the setElement out of bound;
	Point pt(10, 10);
	cout << "let's try SetElement() out of bound"<<endl;
	array.SetElement(pt, 10);

	// Now let's copy the array over to array_1 in order to test the copy constructor.
	Array array_1(array);
	//check the content of array_1, see if everything is copied properly.
	cout << "The content of copy of array, array_1 is: ";
	for (int i = 0; i < array.Size(); i++)
	{
		cout<<array_1.GetElement(i);
	}
	cout << endl;

	//Now let's generate array_2, assign array to array_2;
	Array array_2(4);
	array_2 = array;
	//check the content of array_2, see if everything is copied properly.
	cout << "Let's make array2=array, the content of array_2 is: ";
	for (int i = 0; i < array.Size(); i++)
	{
		cout <<array_2.GetElement(i);
	}
	cout << endl;

	return 0;
}