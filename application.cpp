/**
 *@file application.cpp
 *@author: Uvaish Bakaliya
 *@date: 10-12-2022
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
			bca.addFrame(inFile);

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
		cout << "Invalid File" << endl;

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
	return 0;
}
