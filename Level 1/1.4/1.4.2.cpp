//Exercise2 Basic C program that asks for text input from the keyboard£¬ using do while.  

#include <stdio.h>			
#include <ctype.h>          

int main()
{
	int c=0;  //the character we currently work on£¬ we need to assume an initial value 0. 
	int prev_char = 0;  //previous character
	int count_chars = -1;  //count of characters, change it from 0 to -1.
	int count_words = -1;  //count of words, change from 0 to -1
	int count_newlines = -1;  //count of newlines, change from 0 to -1
	printf("Please enter the text:");//request user to enter text
	do
	{
		if ((isspace(c) == 0) && (isspace(prev_char) || prev_char == 0)) {  //if c is a space and previous c is not a space,
			count_words++;                                                  //or c is the initial character of the input, c should be the beginning of a word. 
		}
		if (c == 10 || prev_char == 0) {   // "/n" has assic value 10 . 
			count_newlines++;                          //if c is a /n , or it is the beginning of the user input, it should be the beginning of new line 			
		}
		count_chars++;
		prev_char = c;
	} while ((c = getchar()) != 4);


	printf("Amount of characters is: %d \n", count_chars);//Display output
	printf("Amount of words is: %d \n", count_words);
	printf("Amount of newlines is: %d \n", count_newlines);

	return 0;
}



