/*
@file		Geometory Fun.cpp
@author		Masaki Nishi
@version	1.0
Calculate and output
the perimeter and area of a square whose side length is the entered number and
the radius, circumference, and area of a circle whose diameter is the entered number
*/

#include <iostream> // required for cin/cout

using namespace std; // sets the default namespace to std for the program

// Declear PI to calculate the radius, circumference, and area of circle
const float FIVE_DIGITS_PI = 3.1416f;

int main() {
	// Input Variables
	unsigned int squareSideLength;
	unsigned int circleDiameter;

	// Output Variables
	unsigned int squarePerimeter;
	unsigned int squareArea;
	float radius;
	float circumference;
	float circleArea;

	// Get a whole number
	cout << "Please enter a whole number: ";

	// Set a whole number to use as a square side length and a circle diameter
	cin >> squareSideLength;
	circleDiameter = squareSideLength;

	// Calculate for square
	squarePerimeter	= squareSideLength * 4;
	squareArea		= squareSideLength * squareSideLength;
	// Calculate for circle
	circumference	= FIVE_DIGITS_PI * circleDiameter;
	radius			= circumference / FIVE_DIGITS_PI / 2;
	circleArea		= FIVE_DIGITS_PI * radius * radius;

	// Output the square side length, the perimeter, and the area.
	cout << "\nA square with side length of "	<< squareSideLength << "\n\t"
		 << "has a perimeter of "				<< squarePerimeter	<< "\n\t"
		 << "has an area of "					<< squareArea		<< "\n\n";

	// Output the circle diameter, the radius, the circumference, and the area
	cout << "A circle with a diameter of "	<< circleDiameter	<< "\n\t"
		 << "has a radius of "				<< radius			<< "\n\t"
		 << "has a circumference of "		<< circumference	<< "\n\t"
		 << "has an area of "				<< circleArea		<< "\n";
}
