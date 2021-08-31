//Exercise 6: write a C-program that shifts any number two places to the right 
#include <stdio.h>			

int main()
{
	int num;  

	printf("Enter a number: ");// request user input
	scanf_s("%d", &num);

	num = num >> 2;//shift number two places to right
	printf("The number shifted two places to the right is: %d \n", num);//Output should be the shifted result

	//then we will output an indication of whether a logical or arithmetic shift is performed 
	
	if (num < 0) {              
		printf("arithmetic shift; 1 shifted in at left side.\n");
	}
	else {
		printf("logical shift; 0 shifted in at left side.\n");
	}

	return 0;
}