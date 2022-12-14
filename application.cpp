/*
	Code Implementer: Uvaish Bakaliya
	Project 3(CS251): Animated Bar Chart (Fall 2022)
	Date: 10-12-2022
	Code written In: Visual Studio code(VSC)
	---------------------------------
		***Creative component***
	---------------------------------
	@details:
	* Search for the frame in two files, and only animate both files if the frame is found in both.

	* functions that are made for the creative component:
	- readFile() in main.cpp
	- takes the argument's file name into consideration.

	- animateFoundedFarms() in barchartanimate.h
	- Arguments the function takes are:
	- similar to animate(), but with an additional frame for the frame that will be searched
		(user would like to search)
*/

#include "headerFiles/barchartanimate.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

// Used for Creative component to read the files
BarChartAnimate readFile(string fileName)
{
	ifstream inFile(fileName);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	if (inFile.fail())
	{
		cout << "Invalid File" << endl;
		exit(0);
	}
	else
	{
		while (!inFile.eof())
		{
			bca.addFrame(inFile);
		}
		inFile.close();
	}
	return bca;
}

int main()
{
	// read the file and get the first few lines of the file
	// (title, x-lable, source)
	string fileName = "dataFiles/cities.txt";
	ifstream inFile(fileName);
	string title;
	getline(inFile, title);
	string xLabel;
	getline(inFile, xLabel);
	string source;
	getline(inFile, source);

	// build a object for the given file
	BarChartAnimate bca(title, xLabel, source);

	// check if the file entered is valid:
	if (inFile.fail())
	{
		cout << "Invalid File" << endl;
	}
	// if valid then:
	else
	{
		// read the file and build frame
		while (!inFile.eof())
			bca.addFrame(inFile);
		inFile.close();
		// animate the frames by given max bars to print in each iterations
		// and how many frames
		bca.animate(cout, 12, -1);
	}

	/*---------------------
	Creative component implementations
	---------------------*/
	/*
	string frameToSearch, fileName1, fileName2;
	int range;
	cout << "Enter the #1 File Name: ";
	cin >> fileName1;
	cout << "Enter the #2 File Name: ";
	cin >> fileName2;
	cout << "Processing Files ...." << endl;
	cout << "\nEnter Frame To Search: ";
	cin >> frameToSearch;
	cout << "Range You want to display the Frames: ";
	cin >> range;
	cout << "Searching Frames ....\n" << endl;
	BarChartAnimate bca1 = readFile(fileName1);
	BarChartAnimate bca2 = readFile(fileName2);
	bool found1 = bca1.animateFoundedFarms(cout, range, bca1.getSize(), frameToSearch);
	bool found2 = bca2.animateFoundedFarms(cout, range, bca2.getSize(), frameToSearch);

	if (found1 && found2)
	{
		cout << WHITE << "Frame #1(From File '" << fileName1 << "): \n" << endl;
		bca1.animateFoundedFarms(cout, range, bca1.getSize(), frameToSearch);
		cout << WHITE << "\n*********************************************"
						 "*********************************************\n"
			 << endl;
		cout << "Frame #1(From File '" << fileName2 << "): \n" << endl;
		bca2.animateFoundedFarms(cout, range, bca2.getSize(), frameToSearch);
	}
	else
		cout << "*** NOT FOUND ***" << endl;
	*/
	return 0;
}
