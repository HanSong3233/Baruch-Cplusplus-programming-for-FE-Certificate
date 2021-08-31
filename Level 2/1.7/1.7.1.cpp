//Exercise 1:create a function swap that exchange the value of two variable.

//preprocessor
#include <stdio.h>

//define a function,exchange the value of i and j. 
int swap(double* i, double* j)
{
	double a, b;  //a and b are two automatic variable that temperaorily save the value of a and b.

	//we save the pointer i in a and pointer b in j
	a =  *i;
	b =  *j;

	//then we assign pointer *i as b, *j as a, in this way we exchange the value of i and j. 
	*i = b;
	*j = a;

	return 0;
}

int main()
{
	// we assign a as 1.023, b=1.732
	double a = 1.023;
	double b = 1.732;

	printf("The value of a is 1.023 and b is 1.732\n");
	swap(&a, &b);//call the function swap
	
	printf("After the swap function, now the value of a is %.3f and value of b is %.3f\n", a, b);//output the result
	return 0;
}