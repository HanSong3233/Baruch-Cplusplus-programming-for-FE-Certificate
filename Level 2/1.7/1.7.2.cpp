//Exercise 2: construct the length() function. 
#include <stdio.h>			
#define MAXLINE 30			//MAXLINE constant of 30

//string length declaration
int Length(char str[]);

int main()
{
	char string[MAXLINE + 1]; // Line of maximum 30 chars + \0
	int c; // The input character
	int i = 0; // The counter

			   // Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);

	// Get the characters
	while ((c = getchar()) != EOF && i<MAXLINE && c != 26)
	{
		// Append entered character to string
		string[i++] = (char)c;
	}
	string[i] = '\0'; // String must be closed with \0

	printf("String length is %d\n", Length(string));

	return 0;
}

int Length(char str[])
{
	int count = 1; //the counter

	//counter will increase by one until it reach '\0', where the string is closed
	while (str[count] != '\0')
	{
		count++;
	}
	return count;  //return the value of counter. 
}