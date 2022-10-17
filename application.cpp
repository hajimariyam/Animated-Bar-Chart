/*
		CS 251 - Data Structures
		Project 3 - Animated Bar Chart
		Author: Mariyam Haji
		NetID: mhaji7
    	System: Visual Studio Code with Ubuntu (WSL 2) on Windows 10 

		application.cpp - Bar Chart Animation
		Purpose: Produce an animated bar chart using BarChartAnimate 
			(which uses BarChart, which uses Bar).

		Creative Component: 
		
		Description: The console user interface created for BarChartAnimate allows 
			the user to choose the delay time between each frame that is graphed for the 
			animation. The user can enter any number greater than 0 and the higher the 
			number, the more the delay. If the input is <= 0, it is reset to 3. If the 
			input is not a number, the program exits with an error code of -1.

		Purpose: This functionality allows the user more freedom when it comes to viewing
			the animation- if they want to carefully analyze the data, or enjoy a quick data 
			visualization. It could also be used for debugging purposes.

		To Run: In barchartanimate.h, in animate(), uncomment lines 179-194 and line 205 and 
			comment line 206. Run application.cpp, which calls animate() on a BarChartAnimate 
			object. When prompted for input, follow the instructions provided.
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


int main() 
{
	string filename;
	cout << "Enter the name of a data file to generate a bar chart animation: ";
	cin >> filename;

	ifstream inFile(filename);
	if (inFile.fail()) { 
		cout << "Invalid input, exiting program..." << '\n';
		exit(-1);
	}

	// get header lines from data file
	string title, xlabel, source;
	getline(inFile, title);
	getline(inFile, xlabel);
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
	
	bca.animate(cout, 12, -1);

    return 0;
}
