//Exercise 1: write C_program to contains two Marco calls. The first print the variable a, and 
//the seconnd prrint the variable a,b. 
//Marco

# include <stdio.h>  //C style I/O
# include "Defs.h"   //include the file Defs.h

int main()
{
	PRINT1("Hello");  //here we make a = "Hello", in the type of string
	PRINT2("Hello", "C++");//here we make b="C++", in the type of string
	return 0;
}