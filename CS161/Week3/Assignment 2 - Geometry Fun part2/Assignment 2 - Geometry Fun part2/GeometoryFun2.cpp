/*
@file		Geometory Fun.cpp
@author		Masaki Nishi
@version	2.0
Calculate and output
the perimeter and area of a square whose side length is the entered number,
the radius, circumference, and area of a circle whose diameter is the entered number,
the perimeter and area of an equilateral triangle whose side length is equal to the entered number, and
the perimeter and area of a regular polygon whose side length and number of the side is equal to the entered number.
*/

#include <iostream> // required for cin/cout
#include <iomanip> // required for setprecision and fixed
#include <cmath> // required for pow and sqrt

using namespace std; // sets the default namespace to std for the program

const float FIVE_DIGITS_PI = 3.1416f; // Declear PI to calculate the radius, circumference, and area of circle

int main() {
	// Input Variables
	// For a square
	unsigned int squareSideLength;
	// For a circle
	unsigned int circleDiameter;
	// For an equilateral riangle
	unsigned int equilateralTriangleSideLength;
	// For a regular polygon
	unsigned int regularPolygonSideLength;
	unsigned int regularPolygonNumberOfSide;

	// Output Variables
	// For a square
	unsigned int squarePerimeter;
	unsigned int squareArea;
	// For a circle
	float radius;
	float circumference;
	float circleArea;
	// For an equilateral riangle
	unsigned int equilateralTrianglePerimeter;
	float equilateralTriangleArea;
	// For a regular polygon
	unsigned int regularPolygonPerimeter;
	float regularPolygonArea;

	// Get a whole number
	cout << "Please enter a whole number: ";

	// Set a whole number to use as a square side length, a circle diameter and, an equilateral triangle side length
	cin >> squareSideLength;
	circleDiameter = equilateralTriangleSideLength = squareSideLength;

	// Calculate for a square
	squarePerimeter = squareSideLength * 4;
	squareArea		= squareSideLength * squareSideLength;
	// Calculate for a circle
	circumference	= FIVE_DIGITS_PI * circleDiameter;
	radius			= circumference / FIVE_DIGITS_PI / 2;
	circleArea		= FIVE_DIGITS_PI * radius * radius;
	// Calculate for an equilateral triangle
	equilateralTrianglePerimeter	= equilateralTriangleSideLength * 3;
	equilateralTriangleArea			= sqrt(3) * pow(equilateralTriangleSideLength, 2) / 4;

	// Set to Output float number with 3 digits after the decimal point
	cout << setprecision(3) << fixed;
	
	// Output the square side length, the perimeter, and the area.
	cout << "\nA square with side length of "	<< squareSideLength		<< endl
		 << "\thas a perimeter of "				<< squarePerimeter		<< endl
		 << "\thas an area of "					<< squareArea			<< endl;

	// Output the circle diameter, the radius, the circumference, and the area
	cout << "\nA circle with a diameter of "	<< circleDiameter		<< endl
		 << "\thas a radius of "				<< radius				<< endl
		 << "\thas a circumference of "			<< circumference		<< endl
		 << "\thas an area of "					<< circleArea			<< endl;

	// Output the perimeter, and the area of an equilateral triangle
	cout << "\nAn equilateral triangle with side length of "	<< equilateralTriangleSideLength	<< endl
		 << "\thas a perimeter of "								<< equilateralTrianglePerimeter		<< endl
		 << "\thas an area of "									<< equilateralTriangleArea			<< endl;

	// Get a side and number of sides of a regular polygon
	cout << "\nPlease enter a side and, a number of sides after spacing: ";

	// Set a side and numbers of sides to use as a regular polygon side length and, number of the side
	cin >> regularPolygonSideLength >> regularPolygonNumberOfSide;

	// Calculate for a regular polygon
	regularPolygonPerimeter = regularPolygonSideLength * regularPolygonNumberOfSide;
	regularPolygonArea		= regularPolygonNumberOfSide * pow(regularPolygonSideLength, 2) / (4.0 * tan(FIVE_DIGITS_PI / regularPolygonNumberOfSide));

	// Output the perimeter, and the area of a regular polygon
	cout << "\nA regular polygon with side length of "	<< regularPolygonSideLength		<< endl
		 << "and, number of the sides "					<< regularPolygonNumberOfSide	<< endl
		 << "\thas a perimeter of "						<< regularPolygonPerimeter		<< endl
		 << "\thas an area of "							<< regularPolygonArea			<< endl;
}
