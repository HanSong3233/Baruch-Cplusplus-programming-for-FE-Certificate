#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <map>
using namespace std;

int main()
{
	// Rolling dice: Mersenne Twister
	boost::mt19937 myRng;
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));  //set the seed.
	
	//unifrom in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);
	
	map<int, long> statistics;   //initialize a map
	int outcome=0;               //initialize a integer outcome

	for (int n = 0; n <= 1000000; ++n)  // Now loop through and accumulate results in map container statistics
	{
		outcome = six(myRng);  // Generate outcome 
		statistics[outcome]++;  // Store result in the map 
	}

	cout << "How many trials? 1000000" << endl << endl;

	for (int i = 1; i <= 6; ++i) 
	{
		cout << "Trial " << i << " has " << (static_cast<double>(statistics[i]) / 1000000) * 100 << "% outcomes" << endl; // Now output frequency of each result
	}

	statistics.clear(); // Clear content

	return 0;
}