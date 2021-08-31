#include "PerpetualAmericanOption.hpp"	// Header file that contains definition for object called EuropeanOption
#include <sstream>	// C++ stream buffering
#include <iostream> // C++ style I/O
#include <cmath>
#include "Supplementfunction.hpp"

PerpetualAmericanOption::PerpetualAmericanOption() : Option() {}  //default constructor.

PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& source) : Option(source) {}	// Copy constructor.

PerpetualAmericanOption::PerpetualAmericanOption(double K, double sig, double r, double b, double S, string m_type) : Option(0, K, sig, r, b, S, m_type) {}  //constructor with parameter input. 

PerpetualAmericanOption::PerpetualAmericanOption(const vector<double> v) : Option(0, v[0], v[1], v[2], v[3], v[4], (v[5] == 1 ? "C" : "P")) {} //constructor with vector as input. 

PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& source)  	// Assignment operator
{
	// Check to make sure not assigning to myself
	if (this == &source) return *this;

	// Call base class assignment
	Option::operator = (source);

	return *this;
}

PerpetualAmericanOption::~PerpetualAmericanOption() {} // Destructor

double PerpetualAmericanOption::Price() const
{
	if (IsCall())  // Call
		return m_K / (m_y1 - 1)*pow((m_y1 - 1) * m_S /m_y1 /m_K, m_y1);
	else
		return m_K / (1- m_y2)*pow((m_y2 - 1)*m_S / m_y2 / m_K, m_y2);
}

double PerpetualAmericanOption::Price(const double &S) const
{
	if (IsCall())  // Call
		return m_K / (m_y1 - 1)*pow((m_y1 - 1) * S / m_y1 / m_K, m_y1);
	else
		return m_K / (1 - m_y2)*pow((m_y2 - 1)*S / m_y2 / m_K, m_y2);
}


std::vector<double> PerpetualAmericanOption::Price(double Min, double Max, double h) const
{
	std::vector<double> S = Mesher(Min, Max, h);
	std::vector<double> price;
	for (int i = 0; i < S.size(); i++) {
		price.push_back(PerpetualAmericanOption::Price(S[i]));
	}
	return price;
}


std::vector<double> PerpetualAmericanOption::Price(const std::vector<vector<double>> mat) const
{
	std::vector<double> price;
	for (int i = 0; i < mat.size(); i++) {
		PerpetualAmericanOption temp_option = PerpetualAmericanOption(mat[i]);
		price.push_back(temp_option.Price());
	}
	return price;
}

