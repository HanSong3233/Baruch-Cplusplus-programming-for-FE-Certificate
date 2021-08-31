#ifndef Supplementfunction_HPP
#define Supplementfunction_HPP
#include <vector>
#include <iostream>
using namespace std;

std::vector<double> Mesher(double Min, double Max, double h);  //declare a function mesher(), which produce a array of double seperate by size h

void print_vector(const vector<double> &v); //declare a function print vector, which print the vector 

void print_matrix(const vector<vector<double> >& matrix);  //declare a function print matrix, which prints the matrix. 

double N(double x);//function to return the cdf of x

double n(double x);//function to return the pdf of x

#endif
