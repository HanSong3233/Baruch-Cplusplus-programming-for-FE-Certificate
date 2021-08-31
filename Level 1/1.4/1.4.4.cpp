//Exercise 4: print two columns on the screen with the temperature in Fehernheirt and Celsius. 

#include <stdio.h>

int main() {
	int start_temp; //the starting temperature
	int end_temp;   // the ending temperature 
	int step_size;  // step size
	double celsius_temp;  //the celsius_temp

	printf("please enter the start temperature here: ");
	scanf_s("%d", &start_temp);
	printf("please enter the end temperature here: ");
	scanf_s("%d", &end_temp);
	printf("please enter the step_size here: ");
	scanf_s("%d", &step_size);

	int current_temp = start_temp; //set the initial value of current temperture, the temp we work on as start_temp
    printf("Fahrenheit\tCelsius\n");

	while (current_temp <= end_temp)
	{
		celsius_temp = (((double)5) / 9) * (current_temp - 32); //calculate the celcius
		printf("%i\t%10.1f\n", current_temp, celsius_temp);  //print current fahrenheit and celsius
		current_temp += step_size; //update fahrenheit temp
	}
	return 0;
}