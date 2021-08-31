#include "Supplementfunction.hpp";
#include <vector>
#include <iostream>
#include <cmath>
#include <boost/math/distributions/normal.hpp>
using namespace boost::math;
using namespace std;

//declare a function mesher(), which produce a array of double seperate by size h.
std::vector<double> Mesher(double Min, double Max, double h)
{
	int Num_of_elements = (Max - Min) / h + 1;

	vector<double> mesh(Num_of_elements);
	mesh[0] = Min;
	mesh[mesh.size() - 1] = Max;

	for (int n = 1; n < mesh.size() - 1; ++n)
	{
		mesh[n] = mesh[n - 1] + h;
	}

	return mesh;
}

//declare a function print vector, which print the vector 
void print_vector(const vector<double> &v)
{
	vector<double>::const_iterator vi_iterator;
	
	for (vi_iterator = v.begin(); vi_iterator != v.end(); ++vi_iterator)
	{
		cout << *vi_iterator << ", ";
	}
	cout << endl;

}


// Print matrix of option parameters
void print_matrix(const vector<vector<double> >& m)
{
	vector<vector<double> >::const_iterator vvi_iterator;
	vector<double>::const_iterator vi_iterator;
	cout << "S    K    r     T   sig   b  type" << endl;

	for (vvi_iterator = m.begin(); vvi_iterator != m.end(); ++vvi_iterator)
	{
		for (vi_iterator = (*vvi_iterator).begin(); vi_iterator != (*vvi_iterator).end(); ++vi_iterator)
		{
			cout << *vi_iterator << ", ";
		}
		cout << "\n" << endl;;
	}
}

//function to return the cdf of x
double N(double x) 
{
	normal_distribution<>myNormal(0.0, 1.0);
	return cdf(myNormal, x);
}
//function to return derivative pdf of x
double n(double x) 
{
	normal_distribution<> myNormal(0.0, 1.0);
	return pdf(myNormal, x);
}