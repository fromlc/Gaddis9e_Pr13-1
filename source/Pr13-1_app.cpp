//----------------------------------------------------------------------
// Pr13-1_app.cpp
// 
// Author: Tony Gaddis
// Modified by: Prof. Linda C
// 
// Modified app code for Program 13-1 on pp. 732-734
//----------------------------------------------------------------------
#include <iostream>

#include "Rectangle.h"

//----------------------------------------------------------------------
// using symbols
//----------------------------------------------------------------------
using std::cin;
using std::cout;
using std::endl;

//----------------------------------------------------------------------
// local function prototypes
//----------------------------------------------------------------------
bool doAnotherRect(double&, double&);
void displayRect(Rectangle&);

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
	cout << "Enter the width (0 quits): ";
	cin >> rectWidth;

	// 0 width means user wants to quit
	if (!rectWidth) {
		return false;
	}

	// use absolute value
	if (rectWidth < 0) {
		rectWidth = -rectWidth;
	}

	cout << "Enter the length: ";
	cin >> rectLength;

	// use absolute value
	if (rectLength < 0) {
		rectLength = -rectLength;
	}

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
