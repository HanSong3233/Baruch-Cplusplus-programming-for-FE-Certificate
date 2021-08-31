#ifndef OPTION_HPP
#define OPTION_HPP
#include <iostream> // C++ style I/O
#include <vector>
using namespace std;

class Option
{

protected:
    double m_S; // Underlying asset price
	double m_K;  // Strike
	double m_T;  // Expiry
	double m_r;  // Interest rate
	double m_sig;  // Volatility
	string m_type;  // call or put
	double m_b;  // cost of carry


public:
		
	void Copy(const Option& source);  // Copy base class
	// Constructors
	Option(); // Default constructor
	Option(double T,double K,double sig, double r,double b, double S,string m_type);	// Copy constructor
	Option(const Option& source);	// Copy constructor

	Option& operator = (const Option& source); // Assignment operator
	virtual ~Option();	// Destructor

	bool IsCall() const;  // True if option is a call option


	//getter function for result, Core functions that must be implemented in all derived classes
	virtual double Price() const = 0; // Get price

	//getter function S, to unify the syntax. 						  
	double S();
	double K();
	double T();
	double r();
	double sig();
	string type();
	double b();
	
	//setter function
	virtual void S(const double& S_);
	virtual void K(const double& K_);
	virtual void T(const double& T_);
	virtual void r(const double& r_);
	virtual void sig(const double& sig_);
	virtual void type(const string& type_);
	virtual void b(const double& b_);

};
#endif