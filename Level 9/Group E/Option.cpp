#ifndef OPTION_CPP
#define OPTION_CPP
#include "Option.hpp"	// Header file that contains definition for object called VanillaOption
#include <sstream>	// C++ stream buffering
#include <iostream> // C++ style I/O
#include "stdlib.h" // Header file that contains rand(), which generates random numbers

Option::Option() :  m_S(0), m_K(0), m_T(0), m_r(0), m_sig(0), m_type("C"), m_b(0) {}  // Default constructor
Option::Option(double T,double K, double sig,double r, double b, double S, string type) :  m_S(S), m_K(K), m_T(T), m_r(r), m_sig(sig), m_type(type), m_b(b) {}	// Copy constructor
Option::Option(const Option& source) { Copy(source); }	// Copy constructor

// Assignment operator
Option& Option::operator = (const Option& source)
{
	// Check to make sure not assigning to myself
	if (this == &source) return *this;

	// Copy state
	Copy(source);

	return *this;
}

Option::~Option() {}  // Destructor, Destroy pointer to option data struct

bool Option::IsCall() const { return m_type == "C"; }   // True if option is a call option

void Option::Copy(const Option& source)  // Copy private data members
{
	m_S = source.m_S;
	m_K = source.m_K;
	m_T = source.m_T;
	m_r = source.m_r;
	m_sig = source.m_sig;
	m_type = source.m_type;
	m_b = source.m_b;

}


double Option::S() { return m_S; }
double Option::K() { return m_K; }
double Option::T() { return m_T; }
double Option::r() { return m_r; }
double Option::sig() { return m_sig; }
string Option::type() { return m_type; }
double Option::b() { return  m_b; }

//setter function
void Option::S(const double& S) { m_S = S; }
void Option::K(const double& K) { m_K = K; }
void Option::T(const double& T) { m_T = T; }
void Option::r(const double& r) { m_r = r; }
void Option::sig(const double& sig) { m_sig = sig; }
void Option::type(const string& type) { m_type = type; }
void Option::b(const double& b) {  m_b=b; }


#endif