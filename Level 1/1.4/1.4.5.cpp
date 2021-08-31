//Exercise 5: print to columns, Celsius on the left, Fahrenheit on the left, 0-19
#include <stdio.h>			

int main()
{
	double current_temp;
	printf("Celsius\t\tFahrenheit\n"); //print a header text
									   									 
	for (int i = 0; i <= 19; i++) {   //Start with 0, end with 1, step_size 1.
		current_temp = (i * (((double)9) / 5)) + 32;  //calculate the current temp
		printf("%i\t%10.1f \n", i, current_temp); //Print the result 
	}
	return 0;
}