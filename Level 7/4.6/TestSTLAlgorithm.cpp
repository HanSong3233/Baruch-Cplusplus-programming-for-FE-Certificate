#include <list> // List container
#include <algorithm>  // STL algorithms
#include "IsSmaller.hpp"	// Header file that contains definition for object called IsSmaller<t>
#include <iostream>  // C++ style I/O
using namespace std;

//Define a Global checking function that
//return true if number of type T is less than a fixed number of 3
template <class T>
bool func_IsSmallerThan3(const T& t)
{
	T test_val = 3;

	return ((t < test_val) ? 1 : 0);  // Returns true if number of type T is less than 3
}


int main()
{
	std::list<double> l; // Let's create a list of doubles

	for (int i = 0; i < 10; i++)
	{
		l.push_back(i); // Add the values to the list, create a list of zero to nine. 
	}

	// Use count_if algorithm and global checing function to count the number of elements smaller than 3
	cout << "Number of elements smaller than " << 3 << " is: " << count_if (l.begin(), l.end(), func_IsSmallerThan3<double>)<< endl;

	// Use count_if algorithm and function object to count the number of elements smaller than 3
	std::cout << "Number of elements smaller than " << 3 << " using function object is: " << count_if(l.begin(), l.end(), IsSmaller<double>(3)) << endl;

	return 0;
}