#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

int main()
{
	//list
	cout << "Let's create List" << endl << endl;
	list<double> l;     //create a list of double l.
	l.push_front(1);   //push 1 in the front of the list
	l.push_back(2);    //push 2 in the back of the list
	l.push_back(3);    //push 3 in the back of the list
	l.push_front(4);   //push 4 in the front of the list

	cout << "The front of the list is: " << l.front() << endl;  //access the first element of the list
	cout << "The back of the list is: " << l.back() << endl;     //access the last element of the list. 

	//vector
	cout <<endl<< "Let's create Vector" << endl << endl;
	vector<double> v; //create a vector of double, v. 
	
	//add element 1,2,3 to the vector. 
	v.push_back(1);  
	v.push_back(2);
	v.push_back(3);

	// Let's check size/capacity 
	cout << "Size : " << v.size() << endl;
	cout << "Max size : " << v.max_size() << endl;  //check the mazmium size computer allow. 
	cout << "Capacity : " << v.capacity() << endl;

	//access the first element using index operator.
	cout <<endl<< "The first element in the vector is: " << v[0] << endl<<endl;

	//add one more element using push back
	v.push_back(4);

	// Let's check size/capacity 
	cout << "Size : " << v.size() << endl;//check the size of vector v.
	cout << "Max size : " << v.max_size() << endl;  //check the mazmium size computer allow. 
	cout << "Capacity : " << v.capacity() << endl<<endl;   //check the capcity of vector v


	cout << "The last element in the vector is: " << v.back() << endl;//print the last element of vector to see if it add correctly

	cout << endl<<"Let's create Map" << endl << endl;
	map<string, double> m;

	// Fill map and access elements using [] operator
	m["apple"] = 1;
	m["banana"] = 2;
	m["car"] = 3;
	m["duck"] = 4;

	// Now output the result. 
	cout << m["apple"] << endl;
	cout << m["banana"] << endl;
	cout << m["car"] << endl;
	cout << m["duck"] << endl;
	cout << "Map size: " << m.size() << endl;

	return 0;
}
