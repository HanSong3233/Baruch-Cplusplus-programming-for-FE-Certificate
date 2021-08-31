// NumericArrayException.hpp
// Header file for NumericArrayException

#ifndef NumericArrayException_HPP
#define NumericArrayException_HPP
#include <iostream> // C++ style I/O
using namespace std;

class NumericArrayException{
private:
	int m_size;  // Contains erroneous array size

public:
	// Constructors
	NumericArrayException();  // Default constructor
	NumericArrayException(int m_size);  // Overload constructor with size as argument
	NumericArrayException(const NumericArrayException& source);	// Copy constructor

	NumericArrayException& operator = (const NumericArrayException& source);	// Assignment operator
	virtual ~NumericArrayException();	// Destructor

	virtual std::string GetMessage() const;  // Return a message string saying two arrays don't have the same size
};

#endif 