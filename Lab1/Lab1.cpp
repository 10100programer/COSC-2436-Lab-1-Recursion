// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Comsci.h"
float power(float a, int b);// a is number and b is power of
float flip(float a);
void lab15_1();
void mainmenu();
void lab15_2();
void starsloop(int cts);
void starsrecursion(int cts);
std::string starprt(int num);
bool palindrome(std::string input, std::string buffer = "", int count = 0, bool test = false);
int main()
{	
	starsloop(4);
	starsrecursion(4);

	if (palindrome("radar") == true)
		std::cout << "yes";
	else
		std::cout << "no";
	pause("STARTS");
	mainmenu();
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
bool palindrome(std::string input, std::string buffer,int count,bool test)
{

	if (input.length() == 0)//default case
		return false;
	int length = input.length();
	buffer = buffer + input[length - count -1];
	//pause("STEP");
	if (buffer.length() == input.length())
	{
		if (buffer == input)
			return true;
		else
			return false;
	}
	return palindrome(input, buffer, count+1,test);
}
void starsrecursion(int cts)
{
	if (cts == 0)
	{
		return;
	}
	std::cout<<starprt(cts) <<std::endl;
	return starsrecursion(cts - 1);
}
void starsloop(int cts)
{
	while (cts > 0) 
	{
		std::cout << starprt(cts) << std::endl;
		cts--;
	}
}
std::string starprt(int num)
{
	std::string str;
	while (num > 0)
	{
		str = str + "*";
		num--;
	}
	return str;
}
void mainmenu()
{
	
	while (true)
	{
		std::string name;
		color("blue");
		std::cout << centertext("***Lab 1:  Recursion***") << std::endl;
		std::cout << centertext("***Please Make A Selction***") << std::endl;
		std::getline(std::cin, name);
		if (name == "a" || name == "A") 
		{
			lab15_1();
		}
		else if(true)
		{
			break;
		}
	}
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
	/* 
	Expected Output
	Please Enter The Number you want to raise by a power 
	2
	Please Enter The Power you want to raise 2 by
	16
	The Answer of 2^16 is 65536
	Press Any Key to try Again or -12 to exit
	*/
}
void lab15_2()
{

}