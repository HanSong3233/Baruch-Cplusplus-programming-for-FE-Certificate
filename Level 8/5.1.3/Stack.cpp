#ifndef Stack_CPP
#define Stack_CPP
#include "Array.hpp"
#include "Stack.hpp"
#include "Exception.hpp"
#include <iostream>
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

//default constructor. 
template<class T,int size>
Stack<T,size>::Stack() : m_current(0), m_array(Array<T>(size)){}

//copy constructor
template<class T,int size>
Stack<T,size>::Stack(const Stack<T,size>& source) : m_current(source.m_current), m_array(Array<T>(m_array))
{
}

//destructor
template<class T,int size>
Stack<T,size>::~Stack(){}

//overloaded assignment operator.
template<class T,int size>
Stack<T, size>& Stack<T, size>::operator = (const Stack<T,size>& source)
{
	if (this = &source) return *this;  //check if assign themselves.
	else
	{
		m_array = source.m_array;
		m_current = source.m_current;
	}
	return *this   //return to the reference
}


template<class T, int size>
void Stack<T,size>::Push(T element)
{
	try 
	{
        m_array[m_current] = element;  // Assign element to current position in array.
		m_current++;  // Increment current position.
	}
	catch (OutOfBoundException a)
	{
		throw StackFullException();
	}
	catch (...)
	{
		cout << "An unhandled exception has occured!" << endl;
	}

}


//pop function, decrement the position and return the element. if Pop() can't be done, return to the original position. 
template<class T,int size>
T Stack<T,size>::Pop()
{                
	try
	{
		                                //If Pop can't be done, it will throw an error,no result will be made,
	                                   //the following steps won't be implemented.  
	T result=m_array[m_current - 1];   //won't be implement, m_current will not change.otherwise, result is the element in the decrement position.
	m_current = m_current - 1;         //Decrement current position. 
	return  result;
	}
	catch (OutOfBoundException a)
	{
		throw StackEmptyException();
	}
	catch (...)
	{
		cout << "An unhandled exception has occured!" << endl;
	}
	
}

#endif