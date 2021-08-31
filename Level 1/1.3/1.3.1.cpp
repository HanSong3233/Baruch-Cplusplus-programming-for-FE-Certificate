//Exercise 1£ºcreate a C-program to print the following

#include <stdio.h>
#include <iostream>
using namespace std;


void F(int i)
{
	if (i % 2) throw i;
	std::cout << "Correct number" << std::endl;
}

int main()
{
	try
	{
		for (int i = 0; i<2; i++)
		{
			F(i); std::cout << "Next iteration" << std::endl;
		}
	}
	catch (int i)
	{
		std::cout << "Exception: " << i << std::endl; return i;
	}

	std::cout << "Finished" << std::endl;

	return 0;
}