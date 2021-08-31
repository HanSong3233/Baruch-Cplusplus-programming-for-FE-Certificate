//Erxercise 1: write a C-program prints the contents of struct called Article. 
#include <stdio.h>;

//struct difinition for article 
struct Article
{
	int Article_number;  //article number
	int Quantity;        //quanity
	char Description[20];//Description, 20 characters maximum. 
};
 
//declare the function that print the contents of article struct
int Print(struct Article *article)
{
	printf("The Article number is %i\n", article->Article_number);  
	printf("The Quantity of article is %i\n", article->Quantity);
	printf("The description is %s\n", article->Description);
	return 0;
}

int main()
{
	struct Article a = { 15, 25, "No name" };  //Initialize contents of struct article a
	Print(&a); //call the print function
	return 0;
}