//Exercise1.3.5.cpp
//Basic C program that clearly shows the difference between --i and i--.

#include <stdio.h>

int main()
{
	int a = 1;  // let us make a=1
	int b, c;

	b = ++a;   //we define b= ++a
	a = 1;
	c = a++;   // we define c= a++ 

	printf("Let us assume a=1 \n");
	printf("the result of b=++a is %d \n", b); //print the result of ++a
	printf("the result of c=a++ is %d \n", c);  //print the result of a++
}