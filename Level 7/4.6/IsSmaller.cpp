#ifndef IsSmaller_CPP
#define IsSmaller_CPP
#include "IsSmaller.hpp"

template <class T>
IsSmaller<T>::IsSmaller() : m_CompareValue(0) {}  // Default constructor, set compare value to zero

template <class T>
IsSmaller<T>::IsSmaller(const T& compare_value) : m_CompareValue(compare_value) {}  // Overload constructor that sets the compare value

template <class T>
IsSmaller<T>::IsSmaller(const IsSmaller<T>& source) : m_CompareValue(source.m_CompareValue) {}  // Copy constructor

																								
template <class T>
IsSmaller<T>& IsSmaller<T>::operator = (const IsSmaller<T>& source)// Overloaded Assignment operator
{
	// Check if assigning to myself
	if (this == &source) return *this;

	// Copy state
	m_CompareValue = source.compare_value;

	return *this;  // Return the reference
}

template <class T>
IsSmaller<T>::~IsSmaller() {}  // Destructor

// Overloaded () operator
// Returns true if number of type T is less than data member m_compareValue
template <class T>
bool IsSmaller<T>::operator() (const T& t) const
{
	return ((t < m_CompareValue) ? 1 : 0);  // Returns true if number of type T is less than data member m_compareValue
	                                        // else return false. 
}

#endif