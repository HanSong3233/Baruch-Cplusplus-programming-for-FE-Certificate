//Exercise 7: efficiently multiplies a number by a factor 2 to the power n.

#include <stdio.h>	

int main()
{
	int number = 0;
	int power_n = 0;


	printf("Please enter a number: ");	//request user to enter number
	scanf_s("%d", &number);

	printf("Enter a number for n: ");//request user to enter n
	scanf_s("%d", &power_n);

	number = number << power_n;  // multiplying by 2 to the power n by n shift to the left
						   
	printf("The result is: %d \n", number);//output result

	return 0;
}