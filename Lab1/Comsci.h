/*
Comsci.h											         		
Standard header to be included with programs created in Computer Science related classes
Version	:1.2b
Created	:April		25th 2015
Modified:January	29th 2017
*/

//#include "stdafx.h"
#include <iostream>
#include "windows.h"
#include <conio.h>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <cmath>
#include <fstream>
#define spacer "|------------------------------------------------------------------------------|"

int splash(std::string title = "Untitled", std::string purpose = "N/A") //splash screen for programs
{
	
	//std::cout << "********************************************************************\n";
	std::cout << spacer;
	std::cout << " Using Comsci.h \n";
	std::cout << " Program Name	: "<< title << std::endl;
	std::cout << " Description	: " << purpose << std::endl;;
	std::cout << spacer<<std::endl;
	//std::cout << "********************************************************************\n";
		return 0;
}

void pause(std::string word = "Press any key to continue\n") //easy pause command
{
	std::cout << word;
	std::cin.get();
}
int color(std::string doscolor) //Simple color handler
{
	std::string syscolor; // green, default, blue
	{
		if (doscolor == "green")
			doscolor = "0A";
		if (doscolor == "default")
			doscolor = "07";
		if (doscolor == "blue")
			doscolor = "9E";
		syscolor = "color " + doscolor;
		system(syscolor.c_str());
		return 3;
	}
}
std::string centertext(std::string imput)
{
	std::string z2;
	int math;
	int screenwidth = 78;
	math = (78 - imput.length()) / 2;
	if (imput.length() > 80)
		goto exit;
	int counter = 0;
	while (math > counter)
	{
		z2 = z2 + " ";
		counter++;
	}
	z2 = z2 + imput;
	exit:
	return z2;

}
//EOF