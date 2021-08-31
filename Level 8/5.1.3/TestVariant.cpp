//Excercise 3: Test variant: create a function that ask user the output to create and return that.
#include <iostream>    //C++ I/o
#include <string>     
#include <boost/variant.hpp>
#include "Point.hpp"   //Header file that contains definition for Point
#include "Circle.hpp"   //Header file that contains definition for Point
#include "Point.hpp"    //Header file that contains definition for Point
#include "Visitor.hpp"   //Header file that contains definition for Point
using namespace std;

// Prompts user to choose a shape
// returned to user as a variant of type variant<Point, Line, Circle>
boost::variant<Point, Line, Circle> ReturnShape()
{
	boost::variant<Point, Line, Circle> myType;
	int type = 0;  // To be used for input

	cout << "What shape type to create (1=Point, 2=Line, or 3=Circle): " << endl;  // ask user to enter their input
	cin >> type;  // Obtain input

	switch (type)  // Determine which variant to return
	{
	case 1:
		myType = Point(1, 1);  // Create a Point and return it to function caller
		break;
	case 2:
		myType = Line(Point(1, 1), Point(2, 2));  // Create a Line and return it to function caller
		break;
	case 3:
		myType = Circle(Point(1, 1),1);  // Create a Circle and return it to function caller
		break;
	}

	return myType;  // Now return the variant
}

int main()
{
	// Create a typedef for a ShapeType variant that contains a Point, Line, or Circle
	typedef boost::variant<Point, Line, Circle> MyShapeType;
	
	MyShapeType test_variant = ReturnShape();  // Prompt user to choose a shape, returning the variant

	cout << "Variant chosen is: " << test_variant << endl << endl;  // Output result

	Line l;  // Try to get the value out of the variant using boost::get<T>()
	try
	{
		l = boost::get<Line>(test_variant);  // This will error at run-time if I didn't choose line in the ReturnShape() function above
	}
	catch (boost::bad_get& err)
	{
		cout << "Error: " << err.what() << endl << endl;
	}
	//we can see that it will throw a exception if we do not choose a line.

	boost::apply_visitor(Visitor(1, 1), test_variant);  // Now let's move the variant's coordinates by 1 and 1 using the visit we defined. 
	
	cout << "Value after moving variant using delta x=1 and delta y=1 is: " << test_variant << endl;  // Output the result
	
	return 0;
}



