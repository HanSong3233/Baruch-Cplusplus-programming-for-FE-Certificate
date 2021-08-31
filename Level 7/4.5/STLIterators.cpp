#include <iostream>
using namespace std;
#include "Sum.hpp"

int main()
{
	list<double> l;     //create a list of double l.
	l.push_front(1);   //push 1 in the front of the list
	l.push_back(2);    //push 2 in the back of the list
	l.push_back(3);    //push 3 in the back of the list
	l.push_front(4);   //push 4 in the front of the list

	vector<double> v; //create a vector of double, v. 

	//add element 1,2,3 to the vector. 
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	map<string, double> m; //create a map m. 

	// Fill map and access elements using [] operator
	m["apple"] = 1;
	m["banana"] = 2;
	m["car"] = 3;
	m["duck"] = 4;

	//test the sun that accpet a container.
	cout << "The sum of the list is: " << Sum(l) << endl;
	cout << "The sum of the vector is: " << Sum(v) << endl;
	cout << "The sum of the map is: " << Sum(m) << endl;
	
	//use Sum() that accept 2 iterators, 
	std::cout << "Sum of list, using beginning/end iterator is: " << Sum<list<double> >(l.begin(), l.end()) << endl;  
	std::cout << "Sum of vector, using beginning/end iterator is: " << Sum<vector<double> >(v.begin(), v.end()) << endl; 
	std::cout << "Sum of map, using beginning/end iterator is: " << Sum<string, double>(m.begin(), m.end()) << std::endl; 


	return 0;
}
