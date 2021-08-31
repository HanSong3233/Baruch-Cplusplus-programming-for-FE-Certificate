#ifndef EUROPEAN_OPTION_CPP
#define EUROPEAN_OPTION_CPP
#include "EuropeanOption.hpp"	// Header file that contains definition for object called EuropeanOption
#include <sstream>	// C++ stream buffering
#include <iostream> // C++ style I/O
#include <cmath>
#include <boost/math/distributions/normal.hpp>
#include "Supplementfunction.hpp"
using namespace boost::math;

EuropeanOption::EuropeanOption() : Option() {}

EuropeanOption::EuropeanOption(const EuropeanOption& source) : Option(source)  {}	// Copy constructor

EuropeanOption::EuropeanOption(double T, double K, double sig,double r, double b,  double S,string m_type) : Option(T, K, sig, r, b, S, m_type) {}

EuropeanOption::EuropeanOption(const vector<double> v) : Option(v[0], v[1], v[2], v[3], v[4], v[5], (v[6] == 1 ? "C" : "P")) {} //constructor with vector as input. 

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& source)  	// Assignment operator
{
	// Check to make sure not assigning to myself
	if (this == &source) return *this;

	// Call base class assignment
	Option::operator = (source);

	return *this;
}

EuropeanOption::~EuropeanOption() {} // Destructor

double EuropeanOption::Price() const
{
	if (IsCall())  // Call
		return ((N(m_d1)) * m_S*exp((m_b-m_r)*m_T)) - (m_K * exp(-m_r * m_T) * N(m_d2));
	else
		return (N(-m_d2) * m_K * exp(-m_r * m_T)) - (m_S*exp((m_b - m_r)*m_T) * N(-m_d1));
}

double EuropeanOption::Price(const double &S) const
{
	double d1 = (log(S / m_K) + ((m_b + ((m_sig * m_sig) / 2.0)) * m_T)) / (m_sig * sqrt(m_T));
	double d2 = (log(S / m_K) + ((m_b - ((m_sig * m_sig) / 2.0)) * m_T)) / (m_sig * sqrt(m_T));
	
	if (IsCall())  // Call
		return ((N(d1)) * S*exp((m_b - m_r)*m_T)) - (m_K * exp(-m_r * m_T) * N(d2));
	else
		return (N(-d2) * m_K * exp(-m_r * m_T)) - (S*exp((m_b - m_r)*m_T) * N(-d1));
}


double EuropeanOption::Delta(const double &S) const
{
	double d1 = (log(S / m_K) + ((m_b + ((m_sig * m_sig) / 2.0)) * m_T)) / (m_sig * sqrt(m_T));

	if (IsCall())  // Call
		return exp((m_b-m_r)*m_T)*N(d1);
	else
		return exp((m_b - m_r)*m_T)*(N(d1)-1);
}


double EuropeanOption::Delta() const
{
	if (IsCall())  // Call
		return exp((m_b - m_r)*m_T)*N(m_d1);
	else
		return exp((m_b - m_r)*m_T)*(N(m_d1)-1);
}


double EuropeanOption::Gamma() const
{
	return n(m_d1)*exp((m_b - m_r)*m_T)/(m_S*m_sig*sqrt(m_T));
}


double EuropeanOption::Gamma(const double &S) const
{
	double d1 = (log(S / m_K) + ((m_b + ((m_sig * m_sig) / 2.0)) * m_T)) / (m_sig * sqrt(m_T));

	return n(d1)*exp((m_b - m_r)*m_T) / (m_S*m_sig*sqrt(m_T));
	
}


double EuropeanOption::DeltaApprox(const double& h) const
{ 
	double diff = EuropeanOption::Price(m_S+h)- EuropeanOption::Price(m_S - h);
	return diff / (2 * h);
}

//not for use now, unknown reason. 
double EuropeanOption::GammaApprox(const double& h) const
{
	double diff = EuropeanOption::Price(m_S + h) + EuropeanOption::Price(m_S - h) - 2*EuropeanOption::Price(m_S);
	return diff / (h * h);
}

// Calculate the call(or put) price for a corresponding put(or call) price 
double EuropeanOption::PriceFromParity() const
{
	if (EuropeanOption::m_type == "C")    //if it is a call option
	{
		EuropeanOption PairOption = EuropeanOption::EuropeanOption(m_T, m_K, m_sig, m_r, m_b, m_S, "P");  //we generate a correponding put option
		return PairOption.Price() + m_S - m_K * exp(-m_r*m_T);    //get the price according to the parity
	}
	else
	{
		EuropeanOption PairOption = EuropeanOption::EuropeanOption(m_T, m_K, m_sig, m_r, m_b, m_S, "C");  //we generate a correponding call option
		return PairOption.Price() - m_S + m_K*exp(-m_r*m_T); //get the price according to the parity
	}
}

// Check if a given set of put / call prices satisfy parity
//due to the rounding error, there may be some small deviation from put call parity, here we set the tolerence as 0.01. 
bool EuropeanOption::IsPutCallParity() const
{
	if (EuropeanOption::m_type == "C")    //if it is a call option
	{
		EuropeanOption PairOption = EuropeanOption::EuropeanOption(m_T, m_K, m_sig, m_r, m_b, m_S, "P");  //we generate a correponding put option
		if (abs(PairOption.Price() + m_S - m_K * exp(-m_r*m_T) - EuropeanOption::Price())<0.01) { return true; }   // as there may exist some rounding problem, we 
		else { return false; }
	}
	else
	{
		EuropeanOption PairOption = EuropeanOption::EuropeanOption(m_T, m_K, m_sig, m_r, m_b, m_S, "C");  //we generate a correponding call option
		if (abs(PairOption.Price() + m_K * exp(-m_r*m_T) - m_S - EuropeanOption::Price())<0.01) { return true; }
		else { return false; }
	}
}


std::vector<double> EuropeanOption::Price(double Min, double Max, double h) const
{
	std::vector<double> S = Mesher(Min, Max, h);
	std::vector<double> price;
	for (int i = 0; i < S.size(); i++) {
		price.push_back(EuropeanOption::Price(S[i]));
	}
	return price;
}


std::vector<double> EuropeanOption::Price(const std::vector<vector<double>> mat) const
{
	std::vector<double> price;
	for (int i = 0; i < mat.size(); i++) {
		EuropeanOption temp_option = EuropeanOption(mat[i]);
		price.push_back(temp_option.Price());
	}
	return price;
}

std::vector<double> EuropeanOption::Delta(double Min, double Max, double h) const
{
	std::vector<double> S = Mesher(Min, Max, h);
	std::vector<double> price;
	for (int i = 0; i < S.size(); i++) {
		price.push_back(EuropeanOption::Delta(S[i]));
	}
	return price;
}


std::vector<double> EuropeanOption::Delta(const std::vector<vector<double>> mat) const
{
	std::vector<double> price;
	for (int i = 0; i < mat.size(); i++) {
		EuropeanOption temp_option = EuropeanOption(mat[i]);
		price.push_back(temp_option.Delta());
	}
	return price;
}

std::vector<double> EuropeanOption::Gamma(double Min, double Max, double h) const
{
	std::vector<double> S = Mesher(Min, Max, h);
	std::vector<double> price;
	for (int i = 0; i < S.size(); i++) {
		price.push_back(EuropeanOption::Gamma(S[i]));
	}
	return price;
}


std::vector<double> EuropeanOption::Gamma(const std::vector<vector<double>> mat) const
{
	std::vector<double> price;
	for (int i = 0; i < mat.size(); i++) {
		EuropeanOption temp_option = EuropeanOption(mat[i]);
		price.push_back(temp_option.Gamma());
	}
	return price;
}


#endif