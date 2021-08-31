#ifndef EUROPEAN_OPTION_HPP
#define EUROPEAN_OPTION_HPP
#include <vector>  //  include vector, used as a container
#include "Option.hpp"   // Header file for base class VanillaOption
#include <iostream> // C++ style I/O
using namespace std;

class EuropeanOption : public Option {
private:
	//add new member d1 and d2 to help with the calculation
	double m_d1 = (log(m_S / m_K) + ((m_b + ((m_sig * m_sig) / 2.0)) * m_T)) / (m_sig * sqrt(m_T));    
	double m_d2 = (log(m_S / m_K) + ((m_b - ((m_sig * m_sig) / 2.0)) * m_T)) / (m_sig * sqrt(m_T));     

public:
	// Constructors
	EuropeanOption();  // Default constructor
	EuropeanOption(double T, double K, double sig,double r, double b, double S, string m_type); //constructor with parameters as input.
	EuropeanOption(const std::vector<double> v); //constructor with parameters as input. notice that we define v[6]=1 as call and v[6]=0 as put
	EuropeanOption(const EuropeanOption& source);  // Copy constructor
	EuropeanOption& EuropeanOption::operator = (const EuropeanOption& source);  // Assignment operator
	virtual ~EuropeanOption();	// Destructor

	//getter function
	double Price() const;  // Get Price
	double Delta() const;  // Get Delta
	double Gamma() const;  // Get Gamma
	double Price(const double &S) const; //Get Price, while we set another underlying asset value
	double Delta(const double &S) const; //Get Delta, while we set another underlying asset value
	double Gamma(const double &S) const; //Get Gamma, while we set another underlying asset value
	double DeltaApprox(const double& h) const; // Get delta approximate
	double GammaApprox(const double& h) const; // Get gamma approximate
	
    //Put-call parity derivation.
	double PriceFromParity() const;  // Calculate the call(or put) price for a corresponding put(or call) price 
	bool IsPutCallParity() const;  // Check if a given set of put / call prices satisfy parity

	//getter function for matrix and Array. 
	std::vector<double> EuropeanOption::Price(double Min, double Max, double h) const;    //calculate option price for a monotonely increasing S
	std::vector<double> EuropeanOption::Price(const std::vector<vector<double>>) const;  //calculate the option price with a input matrix. 
	std::vector<double> EuropeanOption::Delta(double Min, double Max, double h) const;    //calculate option price for a monotonely increasing S
	std::vector<double> EuropeanOption::Delta(const std::vector<vector<double>>) const;  //calculate the option price with a input matrix. 
	std::vector<double> EuropeanOption::Gamma(double Min, double Max, double h) const;    //calculate option price for a monotonely increasing S
	std::vector<double> EuropeanOption::Gamma(const std::vector<vector<double>>) const;  //calculate the option price with a input matrix. 

}; 

#endif
