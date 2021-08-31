//Exercise1 Basic C program that asks for text input from the keyboard£¬ using while.  

#include <stdio.h>			
#include <ctype.h>         

int main()
{
	int c = 0;  //the character we currently work on 
	int prev_char = 0;  //previous character
	int count_chars = 0;  //count of characters
	int count_words = 0;  //count of words
	int count_newlines = 0;  //count of newlines
    printf("Please enter the text:");//request user to enter text

	while ((c = getchar()) != 4) {        //shutdown-code ^D (CTRL + D) is entered. that is, c!=4 
		if ((isspace(c) == 0) && (isspace(prev_char) || prev_char == 0)) {  //if c is a space and previous c is not a space,
			count_words++;                                                  //or c is the initial character of the input, c should be the beginning of a word. 
		}
		if (c == 10 ||  prev_char == 0) {   // "/n" has assic value 10, carriage return has a ASSIC value 13 prev_char. 
			count_newlines++;                          //if c is a /n or /r, or it is the beginning of the user input, it should be the beginning of new line 			
		}
		count_chars++;
		prev_char = c;
	}

	printf("Amount of characters is: %d \n", count_chars);//Display output
	printf("Amount of words is: %d \n", count_words);
	printf("Amount of newlines is: %d \n", count_newlines);

	return 0;
}



