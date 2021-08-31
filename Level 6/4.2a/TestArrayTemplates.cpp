//Excercise 1: Templated Array class. Transfer the array to template class.
#include "Array.cpp"// source file that include the template array class
#include "Point.hpp"// header file that inlcude the definition of Point 
#include <iostream> // C++ style I/O
using namespace std;

int main()
{
	Array<Point> point_array_1(3);            // create class Array with type Point
	point_array_1.SetElement(Point(1, 2), 0);   //set the first element to be Point(1,2)
	point_array_1.SetElement(Point(3, 4), 1);   //set the second element to be point (3,4)
	point_array_1.SetElement(Point(5, 6), 2);   //set the third element to be point (5,6)

	for (int i = 0; i < point_array_1.Size(); i++) cout << point_array_1[i] << endl;   //output each of the element
	                                                                                  //to double check	
	Array<Point> point_array_2(3);  //create another Array with type point
	point_array_2 = point_array_1;   //assign point_array_1 to Point-array_2 to check if the = operator works 
	for (int i = 0; i < point_array_2.Size(); i++) cout << point_array_1[i] << endl;  //print each of the element in 
	                                                                                 //array 2 to double check.
	return 0;
}