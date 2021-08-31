// Exercise 5:Statistical Functions
//Modify the code in the file "testnormaldistribution.cpp" to work with exponential distribution instead of normal distribution 
//and Poission distribution instead of gamma distribution

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
#include <vector>
#include <iostream>
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	exponential_distribution<> myexp(1.0); // Default type is 'double'
	cout << "Mean: " << mean(myexp) << ", standard deviation: " << standard_deviation(myexp) << endl;

	// Distributional properties
	double x = 10.25;

	cout << "pdf: " << pdf(myexp, x) << endl;
	cout << "cdf: " << cdf(myexp, x) << endl;

	// Choose another data type and now a N(0,1) variate
	exponential_distribution<float> myexp2;
	cout << "Mean: " << mean(myexp2) << ", standard deviation: " << standard_deviation(myexp2) << endl;

	cout << "pdf: " << pdf(myexp2, x) << endl;
	cout << "cdf: " << cdf(myexp2, x) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

						// Other properties
	cout << "\n***exponential distribution: \n";
	cout << "mean: " << mean(myexp) << endl;
	cout << "variance: " << variance(myexp) << endl;
	cout << "median: " << median(myexp) << endl;
	cout << "mode: " << mode(myexp) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myexp) << endl;
	cout << "kurtosis: " << kurtosis(myexp) << endl;
	cout << "characteristic function: " << chf(myexp, x) << endl;
	cout << "hazard: " << hazard(myexp, x) << endl;

	// Possion distribution
	double lambda = 3.0; // Shape parameter, k
	poisson_distribution<double> myPois(lambda);

	double val = 13.0;
	cout << endl << "pdf: " << pdf(myPois, val) << endl;
	cout << "cdf: " << cdf(myPois, val) << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPois, val));
		cdfList.push_back(cdf(myPois, val));

		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";

	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";

	}

	return 0;
}
