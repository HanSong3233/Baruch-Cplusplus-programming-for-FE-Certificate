//Exercise 6: count how many times each of the numbers 0-4 have been typed. 

#include <stdio.h>

int main()
{
	int c;  //c:characters entered by user					
	int count_0 = 0;//number of  0-4, as well as any other character appear in the text.
	int count_1 = 0;
	int count_2 = 0;
	int count_3 = 0;
	int count_4 = 0;
	int count_other_chars = 0;

	printf("Please enter your text here:");  //request user to enter here texts.
													  
	while ((c = getchar()) != EOF) {   //input will be stopped by CTRL + Z, which is EOF by getchar().
		switch (c) {
		case 48:           //input equals to 0
			count_0++;
			break;
		case 49:          //input is 1
			count_1++;
			break;
		case 50:          //input is 2
			count_2++;
			break;
		case 51:           //input is 3
			count_3++;
			break;
		case 52:           //input is 4
			count_4++;
			break;
		default:count_other_chars++; //input is other characters except 4
		}
	}
		
		printf("Number 0 has been typed %d times \n", count_0);// print the results.
		printf("Number 1 has been typed %d times \n", count_1);
		printf("Number 2 has been typed %d times \n", count_2);
		printf("Number 3 has been typed %d times \n", count_3);
		printf("Number 4 has been typed %d times \n", count_4);
		printf("other characters have been typed %d times \n", count_other_chars);

		return 0;
}


