// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Comsci.h"
float power(float a, int b);// a is number and b is power of
float flip(float a);
int main()
{
	int ans = 1;
	//std::cout << power(5, -2) << std::endl;
	while (ans != -9) {
		std::cin >> ans;
		std::cout << flip(ans);
	}
	pause(); //pauses execution of code to view answer and prints
	return 0;
}
float power(float a, int b)
{
	
	if (b < 0)//negative number handler
	{
		unsigned int  d = b;
		d = b;
		a = flip(a);
		//pause();
	}
	if (a ==0)//nothing to compute
		return 0;
	if (b == 0) //anything to the power of 0 is zero except for zero
		return 1;
	else
		return a *power(a,b-1);
}
float flip(float a)
{
	return 1 / a;
}