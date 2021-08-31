//Circle.hpp a header file that construct a class of Circle.
//with the functionality Radius(), Centrepoint(), ToString(),Area(),Diameter,Circumference. 

#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp" //Header file of Point
#include "Line.hpp"
#include <iostream> // C++ style I/O

using namespace std;
namespace SongHan {
	namespace CAD {

		class Circle
		{
		private:
			double m_radius;		// radius
			Point Centre_point;		// The centrepoint

		public:
			// Constructors and destroctors
			Circle();										// Default constructor
			Circle(const Point& pt, const double& a);		// constructor
			Circle(const Circle& c);						// Copy constructor
			~Circle();										//Destructor

			//Access function				
			double Radius() const;									// get the radius
			Point CentrePoint() const;								// get the centrepoint

			string ToString() const;								//get string to describethe circle

			double Diameter() const;								//get diameter of the circle
			double Area() const;									//get the area of the circle
			double Circumference() const;							//get the circumference of the circle

			// Setter functions for radius and centrepoint	
			void Radius(const double& a);				//set The radius
			void CentrePoint(const Point& pt);			//set The centrepoint

			//operator overlaoding
			Circle& operator = (const Circle & c);
		};

		// Overloaded Ostream << operator
		ostream& operator << (ostream& os, const Circle& c);		// Send to ostream
	}
}

#endif 
