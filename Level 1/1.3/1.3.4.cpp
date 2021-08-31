// Exercise 4£º use the fact that 0(zero)is interpreted as False and non zero is TRUE 
//use ?: opertor to print if someone is married or not.  

#include <stdio.h>

int main()
{
	int married_or_not = 0; //variable=0, which means False

	printf("Is this person married: %s \n", married_or_not ?  "true":"false"); //print the output, here we let printf() the print "true" or "false"
	
	return 0;
}
