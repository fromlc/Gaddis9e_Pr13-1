//----------------------------------------------------------------------
// Pr13-1_app.cpp
// 
// Author: Tony Gaddis
// Modified by: Prof. Linda C
// 
// Modified app code for Program 13-1 on pp. 732-734 of Gaddis 9E
//----------------------------------------------------------------------
#include "Rectangle.h"

#include <cstdlib>
#include <iostream>

//----------------------------------------------------------------------
// using symbols
//----------------------------------------------------------------------
using std::cin;
using std::cout;
using std::endl;
using std::string;

//----------------------------------------------------------------------
// globals
//----------------------------------------------------------------------
Rectangle g_box;		// Define an instance of the Rectangle class

//----------------------------------------------------------------------
// local function prototypes
//----------------------------------------------------------------------
bool doAnotherRect(double&, double&);
void displayRect();
double validateDouble(string&);

//----------------------------------------------------------------------
// entry point
//----------------------------------------------------------------------
int main() {

	double width;		// Local variable for width
	double length;		// Local variable for length

	// app banner
	cout << "\nThis program calculates the area of a rectangle.\n\n";

	// run until user quits
	while (doAnotherRect(width, length)) {

		// Store the rectangle's width and length in the box object
		g_box.setWidth(width);
		g_box.setLength(length);

		displayRect();
	}

	cout << "\nGoodbye!\n\n";

	return 0;
}

//----------------------------------------------------------------------
// - store user's Rectangle dimensions in reference parameters
// - return false when user enters 0 for width, true otherwise
//----------------------------------------------------------------------
bool doAnotherRect(double& rectWidth, double& rectLength) {
	string input;

	cout << "Enter the width (0 quits): ";
	cin >> input;
	rectWidth = validateDouble(input);

	// 0 width means user wants to quit
	if (!rectWidth) {
		return false;
	}

	cout << "Enter the length: ";
	cin >> input;
	rectLength = validateDouble(input);

	return true;
}

//----------------------------------------------------------------------
// display Rectangle data in global g_box
//----------------------------------------------------------------------
void displayRect() {

	cout << "Your rectangle's data:\n";
	cout << "Width: " << g_box.getWidth() << '\n';
	cout << "Length: " << g_box.getLength() << '\n';
	cout << "Area: " << g_box.getArea() << "\n\n";
}

//----------------------------------------------------------------------
// convert user input to a non-negative double value
// if passed string can be converted to a double value,
// return the absolute value, otherwise return 0
//----------------------------------------------------------------------
double validateDouble(string& input) {
	double d = strtod(input.c_str(), nullptr);

	return d >= 0 ? d : -d;
}
