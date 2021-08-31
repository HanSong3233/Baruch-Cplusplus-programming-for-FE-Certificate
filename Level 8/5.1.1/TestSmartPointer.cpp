//Excercise 1: Test smart pointer:
 #include "Array.hpp"// source file that include the template array class
#include "Point.hpp"// header file that inlcude the definition of Point 
#include "Circle.hpp"//header file that include the definition of PointArray
#include "Line.hpp"
#include "Exception.hpp" //Header file that contains definition for object called ArrayException
#include "boost/shared_ptr.hpp"  // Contains all functionality needed to created shared ptr via boost libraries
#include <iostream>  // C++ style I/O
using namespace std;


int main()
{
	cout << "Now testing with smart pointers......" << endl ;

	// Typedef for a shared pointer to shape and
	// a typedef for an array with shapes stored as shared pointers.
	typedef boost::shared_ptr<Shape> ShapePtr;
	typedef Array<ShapePtr> ShapeArray;

	ShapeArray shape_array(3); // Initialize variable to store array of smart pointers

	// Now let's put some smart pointers into the array
	shape_array[0] = ShapePtr(new Line());
	shape_array[1] = ShapePtr(new Circle());
	shape_array[2] = ShapePtr(new Point());

	// Now print them out
	for (int i = 0; i < 3; i++)
		shape_array[i]->Print();
	//By using smart pointer, we can see that all shapes in the array is deleted, so we won't have a memory leak

	return 0;
}

