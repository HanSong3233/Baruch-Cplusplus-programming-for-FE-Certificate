#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "NumericArray.hpp"	// Header file that contains definition for object called Array
#include "NumericArrayException.hpp"	// Header file that contains definition for object called DimensionException

#include <iostream> // C++ style I/O

template <class T>
NumericArray<T>::NumericArray() : Array() {}	 // Default constructor

// Overload constructor that initializes the array size and allocates number of elements specified by size argument
template <class T>
NumericArray<T>::NumericArray(const int& size_array) : Array(size_array) {}

template <class T>
NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array(source) {}	// Copy constructor

template <class T>
NumericArray<T>::~NumericArray() {}  // Destructor

// Overloaded Assignment operator
// Returns array by reference

template <class T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T> &source)
{
	// Check to make sure not assigning to myself
	if (this == &source) return *this;
	else
	{
		// Call base class assignment operator
		Array<T>::operator = (source);
	}
	return *this;  // Return to reference.
}


// overloaded operator *: Scale the elements of the numeric array by a factor
template <class T>
NumericArray<T> NumericArray<T>::operator * (const T num)
{
	NumericArray<T> Scaled_Numeric_Array((*this).Size());  // Initalize variable Scaled_Nnumeric_Array

	for (int i = 0; i != (*this).Size(); i++)
	{
		Scaled_Numeric_Array[i] = (*this)[i] * num;  // Scale each element by a factor
	}

	return Scaled_Numeric_Array;  // Return Scaled_Numeric_Array
}

// overloaded + operator Add the elements of two numeric arrays. 
template <class T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& source)
{
	//Throw exception is array sizes do not equal
	if ((*this).Size() != source.Size())
	{
		throw NumericArrayException(); // Numeric array sizes don't equal, throw an DimensionException exception
	}
	else
	{
		NumericArray<T> Sum_Numeric_Array((*this).Size());  // Initialize a new array called Sum_Numeric_Array 

		for (int i = 0; i != (*this).Size(); i++)
		{
			Sum_Numeric_Array[i] = (*this)[i] + source.GetElement(i);  //sum the element in both array and assign it into Numeric_Array
		}

		return Sum_Numeric_Array;
	}
}


template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& source)//dotproduct function, return the dot product of two numeric array. 
{
	//Throw exception is array sizes do not equal
	if ((*this).Size() != source.Size())
	{
		throw NumericArrayException(); // Numeric array sizes don't equal, throw an DimensionException exception
	}
	else
	{
		T DotProduct = 0;  // Init variable DotProduct of type T

		for (int i = 0; i != (*this).Size(); i++)
		{
			DotProduct = DotProduct + ((*this)[i] * source.GetElement(i));  // First multiple element in each array, and then use summation
		}

		return DotProduct;  // Return DotProduct calc
	}
}
#endif // NumericArray_CPP