//Exercise 2: write a program to calculate the surface of tranigles
#include <stdio.h>

int main() 
{
	int base, height;
	printf("please enter the height:");   //require user to enter height
	scanf_s("%d", &height);

	printf("Please enter the base:");  //require user to enter base
	scanf_s("%d", &base);

	printf("The area of the tranigle is %f \n", 0.5*height*base); //print the output
	return 0;
}