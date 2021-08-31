//Exercise 2: read the characters from the keyboard, display the input in a file. 
//The file to write must be specific by the user  

//Preprocessor
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	FILE* file; //file to create.  
	int c;  //c is the input characters
	char file_name[20]; //file_name is the file user to write

	printf("Please enter the name of file you want to write: ");
	scanf("%s", &file_name);

	printf("please enter your input here, end with CTRL+SHIFT+A:");  //request user to input their text. 
																		//CTRL+A seems to be selecting all in my computer so I use CTRL+AHIFT+A
	file = fopen(file_name, "w");
	//get all the input character and write whatever in the input
	while ((c = getchar()) != 1) {
		fputc(c, file);   //put all in the file 
	}

	printf("CTRL+SHIFT+A is a correct ending.");// notify the user it ends properly.
	
	fclose(file);  //Close the file
	return 0;
}
