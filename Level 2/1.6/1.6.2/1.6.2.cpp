//Exercise 2: create two marcos MAX2(x,y) and MAX3(x,y,z)

//preprocessor
#include <stdio.h>
#include "Defs.h" //include the file Defs.h

int main()
{
	double x, y, z;  //define the value of x,y,z
	x = 1.05;
	y = 2.31;
	z = 1.43;

	printf("Here we assign x=1.05, y= 2.31, z=1.43\n");
	printf("The maxmum value of x and y is %.2f\n", MAX2(x,y));  //output the result of MAX2
	printf("The maximum value of x,y and z is %.2f\n", MAX3(x, y, z));//output the result of MAX3
	return 0;
}