//Exercise 1: read the characters from the keyboard and shows them on the screen. 

//Preprocessor
# include <stdio.h>

int main()
{
	int c;  //c is the input characters
	printf("please enter your input here, end with CTRL+SHIFT+A: \n");  //request user to input their text. 
    //CTRL+A seems to be selecting all in my computer so I use CTRL+AHIFT+A

	//get all the input character and them display them with function putchar()
	while ((c = getchar()) != 1) {  
		putchar(c);
	}

	printf("\nCTRL+SHIFT+A is a correct ending.");// notify the user it ends properly.

	return 0;
}
