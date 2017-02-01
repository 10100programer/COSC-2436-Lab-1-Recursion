// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Comsci.h"
#include <time.h>
float power(float a, int b);// a is number and b is power of
float flip(float a);
void lab15_1();
void mainmenu();
void lab15_2_1();
void lab15_2_2();
void lab15_2_3();
void lab15_3_1();
void lab15_3_2();
void starsloop(int cts);
void starsrecursion(int cts);
std::string starprt(int num);
double fibonacci_loop(double n);
bool palindrome(std::string input, std::string buffer = "", int count = 0, bool test = false);
int main()
{	
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
double fibonacci_loop(double n)//use positive double
{
	if (n < 0)//check for positive number
		return -9;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	n = n - 1;
	double a = 0;
	double b = 1;
	double c;
	c = a + b;
	while (n>0)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
double fibonacci_rec(double n)//use positive double
{
	if (n < 0)//check for positive number
		return -9;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
	{
		return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
	}
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
		system("cls");
		color("blue");
		//std::cout << centertext("***Lab 1:  Recursion***") << std::endl;
		//std::cout << centertext("***Please Make A Selction***") << std::endl;
		std::cout << spacer;
		std::cout << "|                                  Main Menu                                   |\n";
		std::cout << spacer;
		std::cout << std::endl;
		std::cout << "+---+-------+------------------------------------------------------------------+";
		std::cout << "|Key|Program|                           Description                            |";
		std::cout << "+===+=======+==================================================================+";
		std::cout << "|*A*|lab15_1  |Recursive power program\n";
		std::cout << "|*B*|lab15_2_1|Loop star program\n";
		std::cout << "|*C*|lab15_2_2|Recursive star program\n";
		std::cout << "|*D*|lab15_2_3|Palindrome detection program\n";
		std::cout << "|*E*|lab15_3_1|fibonacci program Loop\n";//update when this part is finished
		std::cout << "|*F*|lab15_3_2|fibonacci program Recursive\n";//update when this part is finished
		std::cout << "\\______________________________________________________________________________/";
		std::cout << "Type the letter of the program you want, or type exit to close this program\n";
		std::cout << "Lab15 :>";
		std::getline(std::cin, name);
		if (name == "a" || name == "A") 
		{
			std::system("cls");
			color("green");
			lab15_1();
		}
		if (name == "b" || name == "B")
		{
			std::system("cls");
			color("green");
			lab15_2_1();
		}
		if (name == "c" || name == "C")
		{
			std::system("cls");
			color("green");
			lab15_2_2();
		}
		if (name == "d" || name == "D")
		{
			std::system("cls"); 
			color("green");
			lab15_2_3();
		}
		if (name == "e" || name == "E")
		{
			std::system("cls");
			color("green");
			lab15_3_1();
		}
		if (name == "f" || name == "F")
		{
			std::system("cls");
			color("green");
			lab15_3_2();
		}
		if(name =="exit")
		{
			return;
		}
	}
}
void lab15_1()//recursive power function
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
}//
void lab15_2_1()//loop star program
{
	splash("loop star program", "Lab 15.2 Steps: Displaying a Pattern");
	while (true) 
	{
		std::cout << "Please Enter The Number of stars you would like or -12 or to goto main menu" << std::endl << ":>";
		int starcount;
		std::cin >> starcount;
		if (starcount == -12)
			return;
		else
		{
			starsloop(starcount);
			std::cout << spacer;
		}
	}
}
void lab15_2_2()//recursive star program
{
	splash("recursive star program", "Lab 15.2 Steps: Displaying a Pattern");
	while (true)
	{
		std::cout << "Please Enter The Number of stars you would like or -12 or to goto main menu" << std::endl << ":>";
		int starcount;
		std::cin >> starcount;
		if (starcount == -12)
			return;
		else
		{
			starsrecursion(starcount);
			std::cout << spacer;
		}
	}
}
void lab15_2_3()//Palindrome
{
	splash("Palindrome detection program", "Lab 15.2 Steps: Recursive Palindrome");
	while (true)
	{
		std::cout << "Please Enter The word you would like  to see if it is a Palindrome or -12 or to goto main menu" << std::endl << ":>";
		std::string word;
		std::getline(std::cin, word);
		if (word == "-12")
			return;
		if (palindrome(word) == true)
			std::cout << word << " is a Palindrome" << std::endl << std::endl;
		else
			std::cout << "No " << word << " is not a Palindrome" << std::endl << std::endl;
	}
}
void lab15_3_1()
{
	double test = 0;
	while (test != -12)
	{
		std::cout << "Please enter a number or enter -12 to exit" << std::endl << ":>";
		std::cin >> test;
		clock_t start = clock();
		std::cout << std::endl << fibonacci_loop(test) << std::endl;
		clock_t end = clock();
		std::cout << "Time elapsed: " <<((double)end - start) / CLOCKS_PER_SEC;

	}
}
void lab15_3_2()
{
	double test = 0;
	while (test != -12)
	{
		std::cout << "Please enter a number enter or -12 to exit" << std::endl << ":>";
		std::cin >> test;

		if (test == -12)
			return;
		clock_t start = clock();
		std::cout << std::endl << fibonacci_rec(test) << std::endl;
		clock_t end = clock();
		std::cout << "Time elapsed: " << ((double)end - start) / CLOCKS_PER_SEC;
	}
}