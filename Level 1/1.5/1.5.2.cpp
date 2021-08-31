//Exercise 2: write a recursive function that prints the factorials of a number.  

#include <stdio.h>

//recieve one value, a, return the factorial. 
long factorial(int a)
{
	if (a == 0 || a == 1) {
		return 1;
	}
	else
	{
		return a*factorial(a - 1);
	}
}

int main()
{
	printf("The value of 6! is %i\n", factorial(6));
}