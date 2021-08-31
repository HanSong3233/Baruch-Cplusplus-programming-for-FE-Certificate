//Exercise 7: show that the frequency of 3 is shown in words
#include <stdio.h>			

int main()
{
	int c ;               //c:characters entered by user
	int count_3 = 0;     //count variables when user enters 3

	printf("Please input your number here:"); //request user to enter here texts
										 
	while ((c = getchar()) != EOF) {   //input will be stopped by CTRL + Z, which is EOF by getchar().
		switch (c) {
		case 51:                       //when input is 3
			count_3++;
			break;
		}
	}

	//Output results
	if (count_3 > 0) {
		switch (count_3) {  
		case 1:
			printf("Number three appears one time.\n");
			break;
		case 2:
			printf("Number three appears two times.\n");
			break;
		default:
			printf("Number three appears more than two times.\n");
			break;
		}
	}
	else {
		printf("Number three does not appear.\n");
	}

	return 0;
}