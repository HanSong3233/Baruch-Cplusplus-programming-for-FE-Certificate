//Exercise 4: create a C program that has a function DayName() which can print the day of a given day-number

// Preprocessor for include files
#include <stdio.h>			// C style I/O

//DayName() function, return the name of day of a given day-number
char* DayName(int num_day, char* days[])
{
	return days[num_day-1];  //returns the day-name based on num_day, Here we use num_day-1 to return the write value. 
}

int main()
{
	//using array to strore the name of days
    //using pointers to make day name hardcoded into the program.
	char* days[7] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thrusday", "Friday", "Saturday"};

	int num_day;  //the days input by the user

	printf("Enter day-number for a given day. Day 1 is a Sunday, Day 7 is a Saturday:");  //Obtain input from user
	scanf_s("%d", &num_day);

	printf("Day %d is a %s\n", num_day, DayName(num_day,days));  //Now output the result,calling the  DayName function

	return 0;
}

