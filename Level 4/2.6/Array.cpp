#include "Array.hpp"	//Header file that contains definition forArray
#include "Point.hpp"	//Header file that contains definition for Point
#include <iostream> // C++ style I/O
using namespace std;
namespace SongHan {
	namespace Containers {
		Array::Array()	 // Default constructor
		{
			m_size = 10;  // Defaulted to 10 elements
			m_data = new Point[10]; //the default set is a array of ten points, all of them is (0,0)
		}

		// constructor with the size of array given
		Array::Array(const int& size_of_array)
		{
			m_size = size_of_array; // Set size based on input argument
			m_data = new Point[m_size];  //generate a array of size m_size, each point is (0,0)
		}

		Array::Array(const Array& a)	// Copy constructor
		{
			m_size = a.m_size;
			m_data = new Point[a.m_size];
			for (int i = 0; i < a.m_size; i++)
			{
				m_data[i] = a.m_data[i];  // Copy each elements in a.
			}
		}

		Array& Array::operator = (const Array& a)  //overloaded operator =
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
				m_data = new Point[a.m_size];  // Allocate new memory before copying the elements

				for (int i = 0; i < a.m_size; i++)
				{
					m_data[i] = a.m_data[i];  // Now copy the elements over
				}
			}
			return *this;  // Return reference, NOT a copy of the object
		}


		// Overloaded [] operator
		// Return reference so the [] operator can be used for read and write elements
		Point& Array::operator [] (int index)
		{
			if (index > m_size)  // Check to make sure index number isn't out of bounds
			{
				cout << "Index out of bounds!" << endl;
				return m_data[0];  // Just return the first element
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
		const Point& Array::operator [] (int index) const
		{
			if (index > m_size)   // Check to make sure index number isn't out of bounds
			{
				cout << "Index out of bounds!" << endl;
				return m_data[0];  // Just return the first element
			}
			else
			{
				cout << "[] bracket operator CONST" << endl;
				return m_data[index];  // Returns by reference
			}
		}

		Array::~Array()		// Destructor
		{
			delete[] m_data; // delete the array itself
		}

		// Accessing member-function for obtaining size of the array, return the m_size	
		int Array::Size() const { return m_size; }	// The size of the array

		// Accessing member-function for obtaining element of the Point array
		Point& Array::GetElement(int pt_index) const
		{
			if (pt_index > m_size)
			{
				cout << "Index out of bounds!" << endl;  //make sure the index number isn't out of bounds
				return m_data[0]; // if it is out of bound, return the first element
			}
			else
			{
				return m_data[pt_index];  // Returns the pt element of array.
			}
		}

		// Setter function for setting an element in a given index.
		void Array::SetElement(const Point& pt, int pt_index)
		{
			if (pt_index > m_size)  // Check to make sure index number isn't out of bounds
			{
				cout << "Index out of bounds!" << endl;  // If out of bounds, ignore the "set"
			}
			else
			{
				this->m_data[pt_index] = pt;
			}
		}
	}
}