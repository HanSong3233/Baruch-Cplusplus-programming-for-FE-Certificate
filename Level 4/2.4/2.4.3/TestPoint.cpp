//Exercise 3: Constructor as conversion operators 
#include "Point.hpp"       //include the header file that contains the definition of point. 
#include "Circle.hpp"
#include "Line.hpp"
#include <iostream>      // C++ style I/O
#include <sstream>		//C++ stream buffering
#include <cmath>
using namespace std;

int main()
{
	Point p(1.0, 1.0);
	//if (p == 1.0) cout << "Equal!" << endl;
	//else cout << "Not equal" << endl;

	//before we make it a explicit conversion operator, the output result is "Equal!".
	if (p == Point(1.0)) cout << "Equal!" << endl;
	else cout << "Not equal" << endl;

	return 0;
}
