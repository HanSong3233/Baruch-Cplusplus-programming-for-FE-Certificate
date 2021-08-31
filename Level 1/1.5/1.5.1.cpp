//Exercise 1: write a function that call a function minus

# include <stdio.h>

//recieve two argumment a,b, returns the difference and print on the screen
int minus(int a, int b)
{
	int result = a - b;
	return result;
}

int main()
{
	printf("the result of 3 - 5 = %i \n", minus(3,5));  //test the output of the function: 3-5
}
