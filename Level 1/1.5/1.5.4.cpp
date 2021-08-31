//Exercise 4: write a recursive function printnumber() to get the number printed. 
#include <stdio.h>			// C style I/O


//receive the value a, print the value a digit by digit;
void printnumber(int a)
{

	if (a < 0) {     //
		a *= -1;   //we make it the positive number
		putchar('-');  //and give a - as the beginning digits
	}

	//Uses the modulo operator (%) to determine the digit to print.
	//Uses the division operator ( / ) to calculate the argument for the recursive call
	if ((a / 10) != 0) {
		printnumber((a / 10));  
		putchar('0' + (a % 10));  //print the output
	} else {
		putchar('0' + a);
	}

}

int main()
{
	printnumber(-123450);  //call printnumber function
	return 0;
}
