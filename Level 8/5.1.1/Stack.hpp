#ifndef Stack_HPP
#define Stack_HPP

#include "Array.hpp"
#include <iostream>
using namespace std;

template <class T, int size> class Stack
{
private:
	int m_current;  //m_corrent
	Array<T> m_array;

public:
	//constructor and destructor
	Stack();//default constructor;	

	Stack(const Stack<T,size>& source);// copy constructor.
	~Stack();//destructor

	//overloaded operator= 
	Stack<T,size>& operator = (const Stack<T,size>& source);
	
	//setter function
	void Push(T element);
	T Pop();
};

#ifndef Stack_CPP
#include "Stack.cpp"
#endif

#endif