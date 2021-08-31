//Excercise 3£º Point Array(concrete infereitance)
#include "Array.hpp"// source file that include the template array class
#include "Point.hpp"// header file that inlcude the definition of Point 
#include "PointArray.hpp"//header file that include the definition of PointArray

#include <iostream> // C++ style I/O
using namespace std;


int main()
{
	PointArray PointArray(3);  //Declare PointArray

	// Add some Points objects into the PointArray
	PointArray[0] = Point(1, 2);
	PointArray.SetElement(Point(3, 4), 1);
	PointArray.SetElement(Point(5, 6), 2);

	// Output values to verify
	for (int i = 0; i != PointArray.Size(); i++) cout << PointArray[i] << endl;

	// Now output the total length between points in the array
	cout << PointArray.Length() << endl;

	return 0;

}