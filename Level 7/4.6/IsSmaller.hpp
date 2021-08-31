#ifndef IsSmaller_HPP
#define IsSmaller_HPP

template <class T>
class IsSmaller
{
private:
	// Member data for class IsSmaller<T>
	T m_CompareValue;  // Variable that stores value to be compared to

public:
	// Constructors
	IsSmaller();  // Default constructor
	IsSmaller(const T& compare_value);  // Overload constructor with compare value as input
	IsSmaller(const IsSmaller<T>& source);  // Copy constructor
	IsSmaller<T>& operator = (const IsSmaller<T>& source);  // Assignment operator
	virtual ~IsSmaller();  // Destructor

	bool operator() (const T& t) const; 	// Overloaded () operator
};


#ifndef IsSmaller_CPP
#include "IsSmaller.cpp"
#endif // IsSmaller_HPP

#endif
