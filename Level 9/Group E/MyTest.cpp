//E(2) compute option price for a monotonically increasing range and visualize them in the excel.
//I do not know why, but when I try to generate the vector using Mesher I defined in Group A. And try to price it, It says no user-defined conversion.
#include "EuropeanOption.hpp"
#include "Supplementfunction.hpp"
#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"
#include <string>
#include <vector>

using namespace std;							//	For readability

void main()
{
	
	//the parametrs for Batch 1-4.
	//define the European Call and Put Option of Batch 1,2,3,4
	//EuropeanOption Call_Option = EuropeanOption(0.25, 65, 0.3, 0.08, 0.08, 60, "C");  //batch 1
	//EuropeanOption Put_Option = EuropeanOption(0.25, 65, 0.3, 0.08, 0.08, 60, "P");   
	//EuropeanOption Call_Option = EuropeanOption(1.0, 100, 0.2, 0.0, 0.0, 100, "C");   //batch 2
	//EuropeanOption Put_Option= EuropeanOption(1.0, 100, 0.2, 0.0, 0.0, 100, "P");
	//EuropeanOption Call_Option = EuropeanOption(1.0, 10, 0.5, 0.12, 0.12, 5, "C");    //batch 3
	//EuropeanOption Put_Option = EuropeanOption(1.0, 10, 0.5, 0.12, 0.12, 5, "P");
	EuropeanOption Call_Option = EuropeanOption(30.0, 100, 0.3, 0.08, 0.08, 100, "C");  //batch 4
	EuropeanOption Put_Option = EuropeanOption(30.0, 100, 0.3, 0.08, 0.08, 100, "P");

	//container for increasing prices. 
	Vector<double,long> StockP(50,0);		

	//	containers of results
	Vector<double,long> Output1(50,0); 
	Vector<double,long> Output2(50,0);
	
	//generate a increasing array of price. 
	for (int i=0;i!=50;i++)		
	{
		StockP[i]=i+10;
	}

	//	calculate option price for different stock prices (other parameters in batches remain the same as before)
	cout<<"Calculating data..."<<endl;
	for (int i=0;i!=50;i++)
	{
		Output1[i]=(Call_Option.Price(StockP[i]));		//	calculate call price
		Output2[i]=(Put_Option.Price(StockP[i]));		//	calculate put price
	}
	cout << endl;

	cout<<"Starting Excel..."<<endl;
	//put the result we get in the excel. 
	try 
	{
		printPairExcel(StockP,Output1, Output2, 
						string("Put and Call Price"), string("Stock Price"), string("Option Price"));
	}
	catch(DatasimException& e)
	{
		e.print();
	}
	cout<<"Finished."<<endl;
}

