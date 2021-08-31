//Exercise 2: tuple 
#include <boost/tuple/tuple.hpp>  //include Tuple class
#include <boost/tuple/tuple_io.hpp> // include I/O for tuples
#include <iostream>                 // C++ style I/O
#include<string>
using namespace std;
using boost::tuple;               // Using declaration of tuple


//define function to print the information of person
void Print_Person(const boost::tuple<string, int, double>& p)
{
	string name = p.get<0>();
	int age = p.get<1>();
	double length = p.get<2>();

	cout << name << "," << age << "," << length << endl;
}

int main()
{
	typedef boost::tuple<string, int, double> Person;  //define the typedef for tuple person, contains person's name, age and length

	//create some person tuple
	Person p1 = boost::make_tuple(string("Allen"), 1, 4);
	Person p2 = boost::make_tuple(string("Bob"), 2, 5);
	Person p3 = boost::make_tuple(string("Carey"), 3, 6);

	//print those tuple using print_person
	Print_Person(p1);
	Print_Person(p2);
	Print_Person(p3);

	//increment the age of p1 by 1
	++get<1>(p1);

	Print_Person(p1);  // check if incrementing of age works
	return 0;
}

