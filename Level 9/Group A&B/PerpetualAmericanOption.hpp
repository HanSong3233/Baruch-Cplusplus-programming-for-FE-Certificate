#ifndef Perprtual_American_Option_HPP
#define Perprtual_American_Option_HPP
#include <vector>  //  include vector, used as a container
#include "Option.hpp"   // Header file for base class VanillaOption
#include <iostream> // C++ style I/O
using namespace std;

class PerpetualAmericanOption : public Option {
private:
	//add new member y1 and y2 to help with the calculation
	double m_y1 = 0.5 - m_b / (m_sig*m_sig) + sqrt((0.5 - m_b / (m_sig*m_sig))*(0.5 - m_b / (m_sig*m_sig)) + 2 * m_r / (m_sig*m_sig));
	double m_y2 = 0.5 - m_b / (m_sig*m_sig) - sqrt((0.5 - m_b / (m_sig*m_sig))*(0.5 - m_b / (m_sig*m_sig)) + 2 * m_r / (m_sig*m_sig));

public:
	// Constructors
	PerpetualAmericanOption();  // Default constructor
	PerpetualAmericanOption(double K, double sig, double r, double b, double S, string m_type); //constructor with parameters as input.
	PerpetualAmericanOption(const std::vector<double> v); //constructor with parameters as input. notice that we define v[6]=1 as call and v[6]=0 as put
	PerpetualAmericanOption(const PerpetualAmericanOption& source);  // Copy constructor
	PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& source);  // Assignment operator
	virtual ~PerpetualAmericanOption();	// Destructor

	//getter function
	double Price() const;  // Get Price
	double Price(const double &S) const; //Get Price, while we set another underlying asset value
	//getter function with vector and array. 
	std::vector<double> PerpetualAmericanOption::Price(double Min, double Max, double h) const;
	std::vector<double> PerpetualAmericanOption::Price(const std::vector<vector<double>> mat) const;
};

#endif
