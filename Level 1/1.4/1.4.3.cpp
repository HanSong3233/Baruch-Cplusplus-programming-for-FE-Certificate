//Exercise1 Basic C program that asks for text input from the keyboard£¬ using switch.  

#include <stdio.h>			
#include <ctype.h>          

int main()
{
	int c = 0;  //the character we currently working on 
	int prev_char = 0;  //previous character
	int count_chars = 0;  //count of characters
	int count_words = 0;  //count of words
	int count_newlines = 0;  //count of newlines¡£ 
	printf("Please enter the text:");//request user to enter text
	while ((c = getchar()) != 4) {            //shutdown-code ^D (CTRL + D) is entered. that is, c!=4
		switch (prev_char==0) {               //check if the character is the beginning of user input   
		case 1:
			count_newlines++;
			count_words++;
			break;
		case 0:		
			switch (isspace(c)) {       //check if character is a space
			case 0:                          //in this case 0 indicates false from isspace()
				switch (isspace(prev_char) == 0) {  //check if previous character is a space, if so  count_words +1
				case 0: count_words++;
					break;
				}
			}
			switch (c == 10) {    //check if character is /n or /r, 
			case 1:	
				count_newlines++;            //then new lines +1
				break;			
			}
		}
		count_chars++;
		prev_char = c;

	}

	printf("Amount of characters is: %d \n", count_chars);//Display output
	printf("Amount of words is: %d \n", count_words);
	printf("Amount of newlines is: %d \n", count_newlines);

	return 0;
}