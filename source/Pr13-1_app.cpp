//----------------------------------------------------------------------
// Pr13-1_app.cpp
// 
// Author: Tony Gaddis
// Modified by: Prof. Linda C
// 
// Modified app code for Program 13-1 on pp. 732-734
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
// local function prototypes
//----------------------------------------------------------------------
bool doAnotherRect(double&, double&);
void displayRect(Rectangle&);
double validateDouble(string&);

//----------------------------------------------------------------------
// entry point
//----------------------------------------------------------------------
int main() {

	Rectangle box;		// Define an instance of the Rectangle class
	double width;		// Local variable for width
	double length;		// Local variable for length

	// app banner
	cout << "\nThis program calculates the area of a rectangle.\n\n";

	// run until user quits
	while (doAnotherRect(width, length)) {

		// Store the rectangle's width and length in the box object
		box.setWidth(width);
		box.setLength(length);

		displayRect(box);
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
// display Rectangle data
//----------------------------------------------------------------------
void displayRect(Rectangle& r) {

	cout << "Your rectangle's data:\n";
	cout << "Width: " << r.getWidth() << '\n';
	cout << "Length: " << r.getLength() << '\n';
	cout << "Area: " << r.getArea() << "\n\n";
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
