#ifndef Sum_HPP
#define Sum_HPP

#include <iostream>
#include <map>
#include <list>
#include <vector>

//sum function declaration for vector and list.
//accept template argument T(vector or list), return double.
template <class T> double Sum(const T& a); 

//sum function declaration for map, return double.
template<class T,class U> double Sum(const map<T, U> &a);

//sum function declaration for two iterators for conatiner lists or vectors. 
template<class T> double Sum(class T::const_iterator start, class T::const_iterator end);

// Sum function declaration for two iterators for map
//template<class T,class U> double Sum(class map<T,U>::const_iterator start, class map<T, U>::const_iterator end);

template<class T, class U> double Sum(class std::map<T, U>::const_iterator start, class std::map<T, U>::const_iterator end);



// template sum function that can be used for a container such as vector or list
// Sums values passed in the generic container, return a double. 
template <class T>
double Sum(const T& a)
{
	double Sum = 0;

	for (T::const_iterator i = a.begin(); i != a.end(); ++i)
		Sum += *i;

	return Sum;
}


// template sum function that can be used for maps
// Sums values passed in the generic container, return a double. 
template <class T,class U>
double Sum(const map<T, U> &a)
{
	double Sum = 0;

	for (map<T,U>::const_iterator i = a.begin(); i != a.end(); ++i)
		Sum += i->second;

	return Sum;
}


//generic sums between two iterators for container such as list or vector, returns a double
template <class T>
double Sum(class T::const_iterator start, class T::const_iterator end)
{
	double Sum = 0;

	for (T::const_iterator i = start; i != end; ++i)
		Sum += *i;

	return Sum;
}

//generic sums between two iterators for map, returns a double
template<class T, class U> 
double Sum(class map<T, U>::const_iterator start, class map<T, U>::const_iterator end)
{
	double Sum = 0;

	for (map<T,U>::const_iterator i = start; i != end; ++i)
		Sum += i->second;

	return Sum;
}



#endif
