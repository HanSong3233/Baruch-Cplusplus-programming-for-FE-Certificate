//Line.hpp a header file that construct a class of line.
//with the functionality start(), end(), ToString(),Length(). 


#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include <sstream>
#include "Point.hpp"
using namespace std;

namespace SongHan {
	namespace CAD {
		class Line
		{
		private:

			Point Start_point;
			Point End_point;

		public:

			// Constructors
			Line();									//constructor with default
			Line(const Point& p1, const Point& p2);	//constructor
			Line(const Line& l); 				// Copy constructor
			virtual ~Line();					// Destructor

			// Accesssing functions
			Point start() const;  //get startPoint
			Point end() const;  //get endPoint
			string ToString() const;//get the name of line
			double Length() const;//get the length of the line. 


			// Modifiers
			void start(const Point& pt);					// Set Point pt1
			void end(const Point& pt);						// Set Point pt2

			//operator overloading
			Line& Line::operator = (const Line& source);    //assignment operator

		};

		// Overloaded Ostream << operator
		ostream& operator << (ostream& os, const Line& l);		// Send to ostream
	}
}

#endif
