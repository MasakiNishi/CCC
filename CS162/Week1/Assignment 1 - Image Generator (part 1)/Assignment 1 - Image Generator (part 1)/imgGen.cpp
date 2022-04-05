/*
@file		Img Gen.cpp
@author		Masaki Nishi
@version	1.0
Creates a simple Portable GrayMap (PGM) image file.
 */

#include <iostream> // required for cin/cout
#include <fstream> // required for ofstream
#include <string> // required to use string type

using namespace std; // sets the default namespace to std for the program

const int WIDTH = 300;
const int HEIGHT = 200;

// function prototypes

/**
Creates the image.
@param	image - the 2D array of image
		hight - the height of the array
@return none
*/
void createImage(unsigned int image[][WIDTH], int height);

/**
Draws a rectangle to the 2D array.
@param	image - the 2D array containing the image
		imgHeight - the height of the image's 2D array
		rectTop - the upper bound of the rectangle
		rectLeft - the left bound of the rectangle
		rectHeight - the height of the rectangle
		rectWidth - the width of the rectangle
		grayLevel - the color to draw with
@return none
*/
void drawRect(unsigned int image[][WIDTH], int imgHeight,
	int rectTop, int rectLeft, int rectHeight, int rectWidth, unsigned int grayLevel
);

/**
Draws a circle to the 2D array.
@param	image - the 2D array containing the image
		height - the height of the image's 2D array
		centerX - the x-coordinate of the center of the circle
		centerY - the y-coordinate of the center of the circle
		radius - the radius of the circle
		grayLevel - the color to draw with
@return none
*/
void drawCircle(unsigned int image[][WIDTH], int height,
	int centerX, int centerY, int radius, unsigned int grayLevel
);

/**
Writes the 2D array to create a PGM file.
@param	image - the 2D array of image
		height - the height of the array
		filename - name of file to create
@return true if image write is successful
*/
bool writeImage(const unsigned int image[][WIDTH], int height, const string fileName);

int main() {
	// Declare array
	unsigned int image[HEIGHT][WIDTH];
	// Call functions
	createImage(image, HEIGHT);
	writeImage(image, HEIGHT, "masakinishi.pgm");
}

// ------------------------------------------------------
void createImage(unsigned int image[][WIDTH], int height) {
	// Fill out background with black color
	for (int row = 0; row < WIDTH; row++) {
		for (int column = 0; column < height; column++) {
			image[column][row] = 0;
		}
	}
	// Draw Rectangle with image, imgHeight, rectTop, rectLeft, rectHeight, rectWidth, grayLevel
	drawRect(image, height, 10, 10, 20, 50, 122);
	drawRect(image, height, 50, 50, 40, 70, 122);
	// Draw Circle with image, height, centerX, centerY, radius, grayLevel
	drawCircle(image, height, 100, 100, 20, 122);
	drawCircle(image, height, 120, 120, 30, 122);
}

// ------------------------------------------------------
void drawRect(unsigned int image[][WIDTH], int imgHeight, int rectTop, int rectLeft, int rectHeight, int rectWidth, unsigned int grayLevel) {
	// Draws the horizontal lines of the rectangle
	if (rectLeft + rectWidth < WIDTH) {
		for (int horizontalLine = rectLeft; horizontalLine < rectLeft + rectWidth; horizontalLine++) {
			image[rectTop][horizontalLine] = grayLevel;
			image[rectTop + rectHeight - 1][horizontalLine] = grayLevel;
		}
	}

	// Draws the vertical lines of the rectangle
	if (rectTop + rectHeight < imgHeight) {
		for (int verticalLine = rectTop; verticalLine < rectTop + rectHeight; verticalLine++) {
			image[verticalLine][rectLeft] = grayLevel;
			image[verticalLine][rectLeft + rectWidth - 1] = grayLevel;
		}
	}
}

// ------------------------------------------------------
void drawCircle(unsigned int image[][WIDTH], int height, int centerX, int centerY, int radius, unsigned int grayLevel) {
	int x = radius;
	int y = 0;
	int err = 0;

	// Midpoint Circle Algorythm to draw circle
	while (x >= y) {
		image[centerY + y][centerX + x] = grayLevel;
		image[centerY + x][centerX + y] = grayLevel;
		image[centerY + x][centerX - y] = grayLevel;
		image[centerY + y][centerX - x] = grayLevel;
		image[centerY - y][centerX - x] = grayLevel;
		image[centerY - x][centerX - y] = grayLevel;
		image[centerY - x][centerX + y] = grayLevel;
		image[centerY - y][centerX + x] = grayLevel;

		if (err <= 0) {
			y += 1;
			err += 2 * y + 1;
		}

		if (err > 0) {
			x -= 1;
			err -= 2 * x + 1;
		}
	}
}

// ------------------------------------------------------
bool writeImage(const unsigned int image[][WIDTH], int height, const string fileName) {
	ofstream pgmFile;

	pgmFile.open(fileName);
	
	// Return false if the file could not be opened
	if (!pgmFile) {
		cout << "File " << fileName << " could not be opened.\n";
		cout << "program terminated.\n";
		return false;
	}

	// Create pgm image
	pgmFile << "P2" << endl;
	pgmFile << WIDTH << ' ' << HEIGHT << endl;
	pgmFile << 255 << endl;

	for (int rIndex = 0; rIndex < HEIGHT; rIndex++) {
		for (int cIndex = 0; cIndex < WIDTH; cIndex++) {
			pgmFile << image[rIndex][cIndex] << ' ';
		}
		pgmFile << endl;
	}

	pgmFile.close();

	// Return true if image created.
	cout << "Image created.";
	return true;
}