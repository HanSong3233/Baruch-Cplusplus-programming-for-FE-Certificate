#ifndef Shape_HPP
#define Shape_HPP
#include <iostream> //C++ style I/O 
#include <sstream>  //C++ style buffering
using namespace std;

class Shape 
{
private:
	double m_id;

public:
	//constructor and destructor 
	Shape();//default constructor
	Shape(const Shape &s);//copy constructor 
	~Shape();//destructor

	//overloaded assignment operator
    Shape& operator = (const Shape &s); 
	
	//access function
	string ToString() const;
	int ID() const;
};

#endif
