#ifndef Array_CPP
#define Array_CPP
#include "Array.hpp"	//Header file that contains definition forArray
#include "Exception.hpp" //Header file that contains definition for exception
#include "Point.hpp"	//Header file that contains definition for Point
#include <iostream> // C++ style I/O
using namespace std;

template <class T>
Array<T>::Array() : m_size(1), m_data(new T[1]) {}	 // Default constructor

// constructor with the size of array given
template <class T>
Array<T>::Array(const int& size_of_array) : m_size(size_of_array), m_data(new T[size_of_array]) { }

template <class T>
Array<T>::Array(const Array& a)// Copy constructor
{	
	m_size = a.m_size;
	m_data = new T[a.m_size];
	for (int i = 0; i < a.m_size; i++)
	{
		m_data[i] = a.m_data[i];  // Copy each elements in a.
	}
}

template <class T>
Array<T>& Array<T>::operator = (const Array& a)  //overloaded operator =
{
	//check to make sure not assigning to myself
	if (this == &a)
	{
		cout << "Function to preclude self-assignment works!" << endl;
		return *this;
	}
	else
	{
		delete[] m_data;  // Delete the internal C array before it is copied

		m_size = a.m_size; // Get size from the object being copied from
		m_data = new T[a.m_size];  // Allocate new memory before copying the elements
		
		for (int i = 0; i < a.m_size; i++)
		{
			m_data[i] = a.m_data[i];  // Now copy the elements over
		}
	}
	return *this;  // Return reference, NOT a copy of the object
}


// Overloaded [] operator
// Return reference so the [] operator can be used for read and write elements
template <class T>
T& Array<T>::operator [] (int index)
{
	if (index >= m_size||index < 0)  // Check to make sure index number isn't out of bounds
	{
		throw OutOfBoundException(index);
	}
	else
	{
		return m_data[index];  // Returns by reference
	}
}

// Overloaded [] operator
// we find we need to add this to make the function work.
// We want the function to be CONST and cannot change the object
// This will tell the compiler array is a constant objects. 
template <class T>
const T& Array<T>::operator [] (int index) const
{
	if (index >= m_size ||index < 0)   // Check to make sure index number isn't out of bounds
	{
		throw OutOfBoundException(index);
	}
	else
	{
		cout << "[] bracket operator CONST" << endl;
		return m_data[index];  // Returns by reference
	}
}

template <class T>
Array<T>::~Array()		// Destructor
{
	delete[] m_data; // delete the array itself
	cout << "Array destroyed" << endl;
}

// Accessing member-function for obtaining size of the array, return the m_size	
template <class T>
int Array<T>::Size() const { return m_size; }	// The size of the array

// Accessing member-function for obtaining element of the Point array
template <class T>
T& Array<T>::GetElement(int pt_index) const
{
	if (pt_index >= m_size||pt_index <0)
	{
		throw OutOfBoundException(pt_index);
	}
	else
	{
		return m_data[pt_index];  // Returns the pt element of array.
	}
}

// Setter function for setting an element in a given index.
template <class T>
void Array<T>::SetElement(const T& pt, int pt_index)
{
	if (pt_index >= m_size || pt_index <0)  // Check to make sure index number isn't out of bounds
	{
		throw OutOfBoundException(pt_index);
	}
	else
	{
		this->m_data[pt_index] = pt;
	}
}


// Initialize static variable s_default_size;
template <typename T>
unsigned int Array<T>::s_default_size = 0;

// Accessing static member function for obtaining default size
// No arguments passed in
// Returns static data member s_default_size as unsigned int
template <typename T>
unsigned int Array<T>::DefaultSize() { return s_default_size; }  // Get the default size of the array

																 // Setter static member function for setting default size
																 // Start_size passed in as unsigned int
template <typename T>
void Array<T>::DefaultSize(unsigned int start_size) { s_default_size = start_size; }  // Set the default size

#endif