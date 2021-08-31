//Exercise 1: CAD and conatiner namespce. Put all my class in my own namespace. place the container classes in the namespace CAD.
#include "Point.hpp"	//include the Header file of Points
#include "Circle.hpp"	//Include the Header file of Circle
#include "Line.hpp"		//Include the Header file of Line
#include "Array.hpp"	//Include the Header file of Array
#include <iostream>  // C++ style I/O

using namespace std;
using SongHan::CAD::Line;      //using declareation for Point class
using namespace SongHan::Containers;     //using directive for complete namespace 
namespace SHC = SongHan::CAD;  //create a shorter alias for SongHan::CAD namespace

int main()
{
	// Create two points and using the + operator to see of Point class works. 
	SongHan::CAD::Point pt1(1,2);
	SongHan::CAD::Point pt2(3,4);
	SongHan::CAD::Point  pt3 = pt1 + pt2;
	cout << "The result of p1+p2 is: " << pt3 << endl;

	//test the line class to see if it works. 
	Line l(pt1, pt2);
	cout << "The description of line we create, l is: " << l << endl;


	//Now let's test the circle class to see if it works. 
	SHC::Circle c_1(pt1,1);    //SHC is an alias namespace
	cout<<"The content of the circle we create is: "<<c_1<<endl;

	//Let's test if the array class works. 
	Array array(3); // Initialize array object with size of 3

	//Add Points to the array using SetElement
	array.SetElement(pt1, 0);
	array.SetElement(pt2, 1);
	array.SetElement(pt3, 2);

	//print the elemet in the array to see if it works. 
	for (int i = 0; i < array.Size(); i++)
	{
		std::cout << array[i] << endl;
	}

	return 0;
}