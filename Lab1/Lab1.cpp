// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Comsci.h"
float power(float a, int b);// a is number and b is power of
float flip(float a);
void lab15_1();

int main()
{	
	lab15_1();
	pause("Program execution Terminated press any key to exit");
	return 0;
}
float power(float a, int b)
{
	
	if (b < 0)//negative number handler
		return -9;//error negative exponent
	if (a ==0)//nothing to compute
		return 0;// zero to any power is zero
	if (b == 0) //anything to the power of 0 is zero except for zero
		return 1;
	else
		return a *power(a,b-1);
}
float flip(float a)
{
	return 1 / a;
}
void lab15_1()
{
	splash("COSC 2436 Lab 1:  Recursion", "Lab 15.1 Designing a Recursive Algorithm for a Power Function");
	int ans = 1;
	int a = 1, b;
	while (a != -12)
	{
		std::cout << "Please Enter The Number you want to raise by a power\n";
		std::cin >> a;
		if (a == -12)
			break;
		std::cout << "Please Enter The Power you want to raise " << a << " by\n";
		std::cin >> b;
		if (b == -12)
			break;
		ans = power(a, b);
		if (ans == -9)
		{
			std::cout << centertext("****ERROR -9 Negative exponet is not allowed****\n\n");
		}
		std::cout << "The Answer of " << a << "^" << b << " is " << ans << newline;
		//std::cout << spacer << centertext(anw) << newline << spacer;
		std::cin.ignore();
		pause("Press Any Key to try Again or -12 to exit\n");
	}
	//std::cout << power(5, -2) << std::endl;
	pause(); //pauses execution of code to view answer and prints
	return;
}