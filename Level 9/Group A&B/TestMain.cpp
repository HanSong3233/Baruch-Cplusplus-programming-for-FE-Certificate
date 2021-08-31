#include <iostream>  //C++ IO
#include "EuropeanOption.hpp"//include the definition of European Option. 
#include"PerpetualAmericanOption.hpp"//include the definition of Perpetual American Option.
#include <vector>  //include vector 
#include "Supplementfunction.hpp"  //include the definition of some supplement function, such as print_vector, print_matrix, n(x), N(x)
using namespace std;

int main()
{
	// Now let's prompt user and let him/her choose whatever option and option parameters
	int OptionType;
	double T, K, sig, r, S, b = 0.0;

	cout << "Choose option you wish to create (0=European, 1=American Perpetual) ";
	cin >> OptionType;

    cout << "Enter T (not applicable to perperpetual american options): ";
	cin >> T;

    cout << "Enter K: ";
	cin >> K;

    cout << "Enter sig: ";
	cin >> sig;
	
	cout << "Enter r: ";
	cin >> r;

	cout << "Enter b: ";
	cin >> b;

    cout << "Enter S: ";
	cin >> S;


	if (OptionType == 0) 
	{
		EuropeanOption Call = EuropeanOption(T, K, sig, r, b, S, "C");
		EuropeanOption Put = EuropeanOption(T, K, sig, r, b, S, "P");
		cout << "Call Price: " << Call.Price() << "   Put Price: " << Put.Price() << endl;
		cout << "The delta of the call option is: " << Call.Delta() << "   of the put option is: " << Put.Delta() << endl;
		cout << "The gamma of the call option is: " << Call.Gamma() << "   of the put option is: " << Put.Gamma() << endl;
	}
	else
	{
		PerpetualAmericanOption Call = PerpetualAmericanOption(K, sig, r, b, S, "C");
		PerpetualAmericanOption Put = PerpetualAmericanOption(K, sig, r, b, S, "P");
		cout << "Call Price: " << Call.Price() << "   Put Price: " << Put.Price() << endl;
	}
}
/*
int main()
{
	cout.precision(10);  //we calculate the number 10 digits
	//A1 Exact solotions for One factor Plains Option.
	//A1 (a) implement the formula and check the answer. 
	cout << "A1.(a)*******************************************"<<endl<<endl;
	//define the European Call and Put Option of Batch 1,2,3,4
	EuropeanOption Batch_1_C = EuropeanOption(0.25, 65, 0.3, 0.08, 0.08, 60, "C");
	EuropeanOption Batch_1_P = EuropeanOption(0.25, 65, 0.3, 0.08, 0.08, 60, "P");
	EuropeanOption Batch_2_C = EuropeanOption(1.0, 100, 0.2, 0.0, 0.0, 100, "C");
	EuropeanOption Batch_2_P = EuropeanOption(1.0, 100, 0.2, 0.0, 0.0, 100, "P");
	EuropeanOption Batch_3_C = EuropeanOption(1.0, 10, 0.5, 0.12, 0.12, 5, "C");
	EuropeanOption Batch_3_P = EuropeanOption(1.0, 10, 0.5, 0.12, 0.12, 5, "P");
	EuropeanOption Batch_4_C = EuropeanOption(30.0, 100, 0.3, 0.08, 0.08, 100, "C");
	EuropeanOption Batch_4_P = EuropeanOption(30.0, 100, 0.3, 0.08, 0.08, 100, "P");

	//Get the Price of those function
	cout << "Batch 1 Call Price: " << Batch_1_C.Price() << "   Put Price: " << Batch_1_P.Price() << endl;
	cout << "Batch 2 Call Price: " << Batch_2_C.Price() << "   Put Price: " << Batch_2_P.Price() << endl;
	cout << "Batch 3 Call Price: " << Batch_3_C.Price() << "   Put Price: " << Batch_3_P.Price() << endl;
	cout << "Batch 4 Call Price: " << Batch_4_C.Price() << "   Put Price: " << Batch_4_P.Price() << endl;

	//A1 (b) put-call parity
	cout <<endl<<"A1.(b)*******************************************" << endl << endl;
	//get the price of option by the put-call paity, we can see that there are the same from we get directly, thus put and call parity holds. 
	cout << "Batch 1 Call Price from parity: " << Batch_1_C.PriceFromParity() << "   Put Price from parity: " << Batch_1_P.PriceFromParity() << endl;
	cout << "Batch 2 Call Price from parity: " << Batch_2_C.PriceFromParity() << "   Put Price from parity: " << Batch_2_P.PriceFromParity() << endl;
	cout << "Batch 3 Call Price from parity: " << Batch_3_C.PriceFromParity() << "   Put Price from Parity: " << Batch_3_P.PriceFromParity() << endl;
	cout << "Batch 4 Call Price from parity: " << Batch_4_C.PriceFromParity() << "   Put Price from Parity: " << Batch_4_P.PriceFromParity() << endl;

	cout << "If Batch 1 follows Put-Call Parity: " << (Batch_1_C.IsPutCallParity() ? "Yes" : "No") << "  " <<(Batch_1_P.IsPutCallParity() ? "Yes" : "No") << endl;
	cout << "If Batch 2 follows Put-Call Parity: " << (Batch_2_C.IsPutCallParity() ? "Yes" : "No") << "  " << (Batch_2_P.IsPutCallParity() ? "Yes" : "No") << endl;
	cout << "If Batch 3 follows Put-Call Parity: " << (Batch_3_C.IsPutCallParity() ? "Yes" : "No") << "  " << (Batch_3_P.IsPutCallParity() ? "Yes" : "No") << endl;
	cout << "If Batch 4 follows Put-Call Parity: " << (Batch_4_C.IsPutCallParity() ? "Yes" : "No") << "  " << (Batch_4_P.IsPutCallParity() ? "Yes" : "No") << endl;


	//A1 (c) outputing vector
	cout << endl << "A1.(c)*******************************************" << endl << endl;
	//Here we use the Batch 1 as a demonstration, other parameters except S is the same as the Batch 1. 
	vector<double> Price_range = Mesher(60, 65, 1); //let's define a increasing range of number: 60,61....65(make it shorter for convinence)
	cout << "The Underlying asset value are: ";
	print_vector(Price_range); //double check if the range is what we what. 
	cout << "The corresponding price of Option are: ";
	print_vector(Batch_1_C.Price(60,65,1));



	//A1 (d) being able to input an matrix. 
	cout << endl << "A1.(d)*******************************************" << endl << endl;

	//let's generate a matrix of of option parameters, note that in the matrix, we define the call option as 1 , put option as 0
	//we use Batch 1 call, Batch 1 put, Batch 2 call and Batch 2 put to generate a matrix. 
	//first let's generate each individual vector. 
	vector<double> vector_batch_1_C { 0.25, 65, 0.3, 0.08, 0.08, 60, 1 };
	vector<double> vector_batch_1_P{ 0.25, 65, 0.3, 0.08, 0.08, 60, 0 };
	vector<double> vector_batch_2_C{ 1.0, 100, 0.2, 0.0, 0.0, 100, 1 };
	vector<double> vector_batch_2_P{ 1.0, 100, 0.2, 0.0, 0.0, 100, 0 };
	vector<vector<double>> input_matrix{ vector_batch_1_C, vector_batch_1_P, vector_batch_2_C,vector_batch_2_P };
	cout << "The matrix of the input is: " << endl;
	print_matrix(input_matrix);
	cout << "The price of Option with such an parameter matrix are: ";
	print_vector(Batch_1_C.Price(input_matrix));   //may need some further simplification here, actually I do not use any information of the instance. 

	//A2 Option sensitivity, aka the Greeks. 
	//A2 (a)
	cout << endl << "A2.(a)*******************************************" << endl << endl;

	EuropeanOption Future_Option_C = EuropeanOption(0.5, 100, 0.36, 0.1, 0, 105, "C");   //generate the call option 
	EuropeanOption Future_Option_P = EuropeanOption(0.5, 100, 0.36, 0.1, 0, 105, "P");
	cout << "The delta of the call option is: " << Future_Option_C.Delta() << "   of the put option is: " << Future_Option_P.Delta() << endl;
	cout << "The gamma of the call option is: " << Future_Option_C.Gamma() << "   of the put option is: " << Future_Option_P.Gamma() << endl;

	//A2 (b) outputing vector
	cout << endl << "A2.(b)*******************************************" << endl << endl;
	//Here we use the call option of the future as a demonstration, other parameters except S is the same as the Batch 1. 
	vector<double> Price_range_f = Mesher(100, 105, 1); //let's define a increasing range of number: 60,61....65(make it shorter for convinence)
	cout << "The Underlying asset value are: ";
	print_vector(Price_range_f); //double check if the range is what we what. 
	cout << "The corresponding delta of Option are: ";
	print_vector(Future_Option_C.Delta(100, 105, 1));

	//A2 (c) input a matrix.
	cout << endl << "A2.(c)*******************************************" << endl << endl;

	//let's generate a matrix of of option parameters, note that in the matrix, we define the call option as 1 , put option as 0
	//we use Batch 1 call, Batch 1 put, Batch 2 call and Batch 2 put to generate a matrix. 
	//first let's generate each individual vector. 
	vector<double> vector_future_option_C{ 0.5, 100, 0.36, 0.1, 0, 105, 1 };
	vector<double> vector_future_option_P{ 0.5, 100, 0.36, 0.1, 0, 105, 0 };
	//generate a matrix with those vector
	vector<vector<double>> input_matrix_future{ vector_future_option_C, vector_future_option_P };
	//print the input matrix. 
	cout << "The matrix of the input is: " << endl;
	print_matrix(input_matrix_future);
	//print the result of delta
	cout << "The Delta of Option with such an parameter matrix are: ";
	print_vector(Future_Option_C.Delta(input_matrix_future));   //may need some further simplification here, actually I do not use any information of the instance. 
	cout << "The Gamma of Option with such an parameter matrix are: ";
	print_vector(Future_Option_C.Gamma(input_matrix_future));

	//A2(d) divided difference
	cout << endl << "A2.(d)*******************************************" << endl << endl;
	cout << "The delta of the call option is: " << Future_Option_C.Delta() << " of the put option is: " << Future_Option_P.Delta() << endl;
	cout << "let's apply dividend difference method with different h." << endl;
	cout << "when h=1, the delta of call option: " << Future_Option_C.DeltaApprox(1) << "   of the put option: " << Future_Option_P.DeltaApprox(1) << endl;
	cout << "when h=0.1, the delta of call option: " << Future_Option_C.DeltaApprox(0.1) << "   of the put option: " << Future_Option_P.DeltaApprox(0.1) << endl;
	cout << "when h=0.01, the delta of call option: " << Future_Option_C.DeltaApprox(0.01) << "   of the put option: " << Future_Option_P.DeltaApprox(0.01) << endl;
	cout << "when h=0.001, the delta of call option: " << Future_Option_C.DeltaApprox(0.001) << "   of the put option: " << Future_Option_P.DeltaApprox(0.001) << endl;
	cout << endl << endl;
	cout << "The Gamma of the call option is: " << Future_Option_C.Gamma() << " of the put option is: " << Future_Option_P.Gamma() << endl;
	cout << "let's apply dividend difference method with different h." << endl;
	cout << "when h=1, the Gamma of call option: " << Future_Option_C.GammaApprox(1) << "   of the put option: " << Future_Option_P.GammaApprox(1) << endl;
	cout << "when h=0.1, the Gamma of call option: " << Future_Option_C.GammaApprox(0.1) << "   of the put option: " << Future_Option_P.GammaApprox(0.1) << endl;
	cout << "when h=0.01, the Gamma of call option: " << Future_Option_C.GammaApprox(0.01) << "   of the put option: " << Future_Option_P.GammaApprox(0.01) << endl;
	cout << "when h=0.001, the Gamma of call option: " << Future_Option_C.GammaApprox(0.001) << "   of the put option: " << Future_Option_P.GammaApprox(0.001) << endl;


	//B1 Perputual American Option. 
	//B1 (a)£¨b£©
	cout << endl << "B1.(a)(b)*******************************************" << endl << endl;

	PerpetualAmericanOption American_Option_C = PerpetualAmericanOption(100, 0.1, 0.1, 0.02, 110, "C");   //generate the call option, notice that for 
	PerpetualAmericanOption American_Option_P = PerpetualAmericanOption(100, 0.1, 0.1, 0.02, 110, "P");
	cout << "The price of the Perpetual American call option is: " << American_Option_C.Price() << "   of the put option is: " << American_Option_P.Price() << endl;

	//B (c) outputing vector
	cout << endl << "B1.(c)*******************************************" << endl << endl;
	//Here we use the American Call Option  in the previous exercise as a demonstration, other parameters except S is the same as the previous one.  
	vector<double> Price_range_2 = Mesher(105, 110, 1); //let's define a increasing range of number: 60,61....65(make it shorter for convinence)
	cout << "The Underlying asset value are: ";
	print_vector(Price_range_2); //double check if the range is what we what. 
	cout << "The corresponding price of Option are: ";
	print_vector(American_Option_C.Price(105, 110, 1));


	//B (d) being able to input an matrix. 
	cout << endl << "B.(d)*******************************************" << endl << endl;

	//let's generate a matrix of of option parameters, note that in the matrix, we define the call option as 1 , put option as 0
	//we use Batch 1 call, Batch 1 put, Batch 2 call and Batch 2 put to generate a matrix. 
	//first let's generate each individual vector. 
	vector<double> Vector_American_Option_C{ 100, 0.1, 0.1, 0.02, 110, 1 };
	vector<double> Vector_American_Option_P{ 100, 0.1, 0.1, 0.02, 110, 0 };
	//make the vector into a matrix. 
	vector<vector<double>> input_matrix_A{ Vector_American_Option_C, Vector_American_Option_P };
	//check the input matrix. 
	cout << "The matrix of the input is: " << endl;
	print_matrix(input_matrix_A);
	//check the results
	cout << "The price of Option with such an parameter matrix are: ";
	print_vector(American_Option_C.Price(input_matrix_A));   //may need some further simplification here, actually I do not use any information of the instance. 

	return 0;
}
*/