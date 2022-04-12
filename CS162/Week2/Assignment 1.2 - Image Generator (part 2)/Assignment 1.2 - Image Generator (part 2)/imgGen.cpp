/*
@file		Img Gen.cpp
@author		Masaki Nishi
@version	1.2
Creates a Portable PixMap (PPM) image file.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int WIDTH = 300;
const int HEIGHT = 200;

struct Color {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

// function prototypes

void createImage(Color image[][WIDTH], int height);

void drawRect(Color image[][WIDTH], int imgHeight,
	int rectTop, int rectLeft, int rectHeight, int rectWidth, Color color
);

void drawCircle(Color image[][WIDTH], int height,
	int centerX, int centerY, int radius, Color color
);

void drawEclipse(Color image[][WIDTH], int radiusX, int radiusY, int centerX, int centerY, Color blue, Color yellow);

void drawGrad(Color image[][WIDTH], int imgHeight,
	int rectTop, int rectLeft, int rectHeight, int rectWidth, Color color
);

bool writeImage(const Color image[][WIDTH], int height, const string fileName);

int main() {
	// Declare array
	static Color image[HEIGHT][WIDTH];
	// Call functions
	createImage(image, HEIGHT);
	writeImage(image, HEIGHT, "nowarinukraine.ppm");
}

/**
Creates the image.
@param	image - the 2D array of image
@param	hight - the height of the array
*/
void createImage(Color image[][WIDTH], int height) {
	// Creates color
	Color blue = { 0, 90, 187 };
	Color vividBlue = { 0, 0, 255 };
	Color yellow = { 255, 213, 0 };
	Color purple = { 137, 1, 188 };
	Color skyblue = { 137, 189, 222 };
	Color green = { 101, 188, 66 };
	Color orange = { 255, 66, 7 };
	Color red = { 255, 8, 1 };

	// Draw Rectangle with image, imgHeight, rectTop, rectLeft, rectHeight, rectWidth, color
	drawGrad(image, height, 0, 0, 28, 300, purple);
	drawGrad(image, height, 28, 0, 29, 300, vividBlue);
	drawGrad(image, height, 57, 0, 29, 300, skyblue);
	drawGrad(image, height, 86, 0, 29, 300, green);
	drawGrad(image, height, 115, 0, 29, 300, yellow);
	drawGrad(image, height, 144, 0, 28, 300, orange);
	drawGrad(image, height, 172, 0, 28, 300, red);
	// Draw Eclipse with image, radiusX, radiusY, centerX, centerY, radius, color
	drawEclipse(image, 80, 130, 100, 150, blue, yellow);
}

/**
Draws a rectangle to the 2D array.
@param	image - the 2D array containing the image
@param	imgHeight - the height of the image's 2D array
@param	rectTop - the upper bound of the rectangle
@param	rectLeft - the left bound of the rectangle
@param	rectHeight - the height of the rectangle
@param	rectWidth - the width of the rectangle
@param	color - the color to draw with
*/
void drawRect(Color image[][WIDTH], int imgHeight, int rectTop, int rectLeft, int rectHeight, int rectWidth, Color color) {
	// Draws the horizontal lines of the rectangle
	if (rectLeft + rectWidth < WIDTH) {
		for (int horizontalLine = rectLeft; horizontalLine < rectLeft + rectWidth; horizontalLine++) {
			image[rectTop][horizontalLine] = color;
			image[rectTop + rectHeight - 1][horizontalLine] = color;
		}
	}

	// Draws the vertical lines of the rectangle
	if (rectTop + rectHeight < imgHeight) {
		for (int verticalLine = rectTop; verticalLine < rectTop + rectHeight; verticalLine++) {
			image[verticalLine][rectLeft] = color;
			image[verticalLine][rectLeft + rectWidth - 1] = color;
		}
	}
}

/**
Draws a circle to the 2D array.
@param	image - the 2D array containing the image
@param	height - the height of the image's 2D array
@param	centerX - the x-coordinate of the center of the circle
@param	centerY - the y-coordinate of the center of the circle
@param	radius - the radius of the circle
@param	color - the color to draw with
*/
void drawCircle(Color image[][WIDTH], int height, int centerX, int centerY, int radius, Color color) {
	int x = radius;
	int y = 0;
	int err = 0;

	// Midpoint Circle Algorythm to draw circle
	while (x >= y) {
		image[centerY + y][centerX + x] = color;
		image[centerY + x][centerX + y] = color;
		image[centerY + x][centerX - y] = color;
		image[centerY + y][centerX - x] = color;
		image[centerY - y][centerX - x] = color;
		image[centerY - x][centerX - y] = color;
		image[centerY - x][centerX + y] = color;
		image[centerY - y][centerX + x] = color;

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


/**
Draws a eclipse to the 2D array.
@param	image - the 2D array containing the image
@param	radiusX - the radius of the X
@param	radiusY - the radius of the Y
@param	centerX - the x-coordinate of the center of the circle
@param	centerY - the y-coordinate of the center of the circle
@param	blue - the color to draw with
@param	yellow - the color to draw with
*/
void drawEclipse(Color image[][WIDTH], int radiusX, int radiusY, int centerX, int centerY, Color blue, Color yellow) {
	int dx, dy, d1, d2, x, y;
	x = 0;
	y = radiusY;

	// Initial decision parameter of region 1
	d1 = (radiusY * radiusY) - (radiusX * radiusX * radiusY) +
		(0.25 * radiusX * radiusX);
	dx = 2 * radiusY * radiusY * x;
	dy = 2 * radiusX * radiusX * y;

	// For region 1
	while (dx < dy)
	{
		// Print points based on 4-way symmetry
		// Fill the top of the eclipse
		if (centerX + x < 100) {
			for (int i = centerY; i < centerY + y; i++) {
				image[centerX + x][i] = blue;
			}
			for (int i = centerY - y; i < centerY; i++) {
				image[centerX + x][i] = blue;
			}
		}
		// Fill the bottom of the eclipse
		else {
			for (int i = centerY; i < centerY + y; i++) {
				image[centerX + x][i] = yellow;
			}
			for (int i = centerY - y; i < centerY; i++) {
				image[centerX + x][i] = yellow;
			}
		}

		// Fill the top of the eclipse
		if (centerX - x < 100) {
			for (int i = centerY; i < centerY + y; i++) {
				image[centerX - x][i] = blue;
			}
			for (int i = centerY - y; i < centerY; i++) {
				image[centerX - x][i] = blue;
			}
		}
		// Fill the bottom of the eclipse
		else {
			for (int i = centerY; i < centerY + y; i++) {
				image[centerX - x][i] = yellow;
			}
			for (int i = centerY - y; i < centerY; i++) {
				image[centerX - x][i] = yellow;
			}
		}

		// Checking and updating value of
		// decision parameter based on algorithm
		if (d1 < 0)
		{
			x++;
			dx = dx + (2 * radiusY * radiusY);
			d1 = d1 + dx + (radiusY * radiusY);
		}
		else
		{
			x++;
			y--;
			dx = dx + (2 * radiusY * radiusY);
			dy = dy - (2 * radiusX * radiusX);
			d1 = d1 + dx - dy + (radiusY * radiusY);
		}
	}

	// Decision parameter of region 2
	d2 = ((radiusY * radiusY) * ((x + 0.5) * (x + 0.5))) +
		((radiusX * radiusX) * ((y - 1) * (y - 1))) -
		(radiusX * radiusX * radiusY * radiusY);

	// Plotting points of region 2
	while (y >= 0)
	{	
		// Print points based on 4-way symmetry
		// Fill the top of the eclipse
		if (centerX + x < 100) {
			for (int i = centerY; i < centerY + y; i++) {
				image[centerX + x][i] = blue;
			}
			for (int i = centerY - y; i < centerY; i++) {
				image[centerX + x][i] = blue;
			}
		}
		// Fill the bottom of the eclipse
		else {
			for (int i = centerY; i < centerY + y; i++) {
				image[centerX + x][i] = yellow;
			}
			for (int i = centerY - y; i < centerY; i++) {
				image[centerX + x][i] = yellow;
			}
		}

		// Fill the top of the eclipse
		if (centerX - x < 100) {
			for (int i = centerY; i < centerY + y; i++) {
				image[centerX - x][i] = blue;
			}
			for (int i = centerY - y; i < centerY; i++) {
				image[centerX - x][i] = blue;
			}
		}
		// Fill the bottom of the eclipse
		else {
			for (int i = centerY; i < centerY + y; i++) {
				image[centerX - x][i] = yellow;
			}
			for (int i = centerY - y; i < centerY; i++) {
				image[centerX - x][i] = yellow;
			}
		}
		
		// Checking and updating parameter
		// value based on algorithm
		if (d2 > 0)
		{
			y--;
			dy = dy - (2 * radiusX * radiusX);
			d2 = d2 + (radiusX * radiusX) - dy;
		}
		else
		{
			y--;
			x++;
			dx = dx + (2 * radiusY * radiusY);
			dy = dy - (2 * radiusX * radiusX);
			d2 = d2 + dx - dy + (radiusX * radiusX);
		}
	}
}

void drawGrad(Color image[][WIDTH], int imgHeight, int rectTop, int rectLeft, int rectHeight, int rectWidth, Color color) {
	// Draws the graduation background
	for (int verticalLine = rectTop; verticalLine < rectTop + rectHeight; verticalLine++) {
		for (int horizontalLine = rectLeft; horizontalLine < rectLeft + rectWidth; horizontalLine++) {
			image[verticalLine][horizontalLine] = color;
		}
	}
}

/**
Writes the 2D array to create a PPM file.
@param	image - the 2D array of image
@param	height - the height of the array
@param	filename - name of file to create
@return true if image write is successful
*/
bool writeImage(const Color image[][WIDTH], int height, const string fileName) {
	ofstream ppmFile;

	ppmFile.open(fileName);

	// Return false if the file could not be opened
	if (!ppmFile) {
		cout << "File " << fileName << " could not be opened.\n";
		cout << "program terminated.\n";
		return false;
	}

	// Create ppm image
	ppmFile << "P3" << endl;
	ppmFile << WIDTH << ' ' << HEIGHT << endl;
	ppmFile << 255 << endl;

	for (int rIndex = 0; rIndex < HEIGHT; rIndex++) {
		for (int cIndex = 0; cIndex < WIDTH; cIndex++) {
			ppmFile << static_cast<int>(image[rIndex][cIndex].red) << " " << static_cast<int>(image[rIndex][cIndex].green) << " " << static_cast<int>(image[rIndex][cIndex].blue) << " ";
		}
		ppmFile << endl;
	}

	ppmFile.close();

	// Return true if image created.
	cout << "Image created.";
	return true;
}