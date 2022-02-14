/*
@file		Fun Fun.cpp
@author		Masaki Nishi
@version	1.0
The previous assignment (LoopFun) had 4 distinct parts,
all of which were implemented in one function (main).
This breaks it into multiple functions to implement the different parts.
*/

#include <iostream> // required for cin/cout

using namespace std; // sets the default namespace to std for the program

// function prototypes

/*
Gets the box number
@param	int(low), int(high)
@return int - boxNum between int low and high
*/
int getInt(int low, int high);

/*
Outputs the range between low and high
@param	int(low), int(high)
@return void
*/
void printRange(int low, int high);

/*
Outputs the average number between low and high
@param	int(low), int(high)
@return void
*/
void printAvg(int low, int high);

/*
Outputs the rectangle
@param	int(height), int(width)
@return void
*/
void printBox(int height, int width);

/*
Outsputs the Wedge
@param	int(height)
@return void
*/
void printWedge(int height);

int main() {
	// Get a boxHeight from the user
	cout << "Enter a box height between (3 and 10): ";
	int boxHeight = getInt(3, 10);

	// Get a boxWidth from the user
	cout << "Enter a box width between (" << boxHeight + 1 << " and 20): ";
	int boxWidth = getInt(boxHeight + 1, 20);

	printRange(boxHeight, boxWidth);
	printAvg(boxHeight, boxWidth);
	printBox(boxHeight, boxWidth);
	printWedge(boxHeight);
}

int getInt(int low, int high) {
	// Sets boxNum to return boxHeight and boxWidth
	int boxNum;
	cin >> boxNum;
	cin.ignore(100, '\n');

	// Continues to get proper Integer (between 3 to 10)
	while (boxNum < low || high < boxNum) {
		cout << "That number is out of bounds : Try again : ";
		cin >> boxNum;
		cin.ignore(100, '\n');
	}
	cout << endl;

	return boxNum;
}

void printRange(int low, int high) {
	// Outputs all numers between the height and width
	cout << "The integers from " << low << " to " << high << " are:" << endl;
	cout << "\t";
	for (int i = low; i <= high; i++) {
		cout << i << " ";
	}
}
void printAvg(int low, int high) {
	// Set a sum and count numbers between the height and width to calculate average
	int count = 0;
	float averageNum = 0.f;

	for (int i = low; i <= high; i++) {
		count += 1;
		averageNum += i;
	}

	// Outputs average between the height and width
	cout << endl;
	averageNum = averageNum / count;
	cout << "and the average of those numbers is " << averageNum << endl;
}

void printBox(int height, int width) {
	cout << endl;

	// Outputs Box
	for (int i = 1; i <= height; i++) {
		// When first line and final line
		if (i == 1 || i == height) {
			// Outputs * until reaching boxWidth
			for (int i = 1; i <= width; i++) {
				cout << "*";
			}
			cout << endl;
			// When middle line
		}
		else {
			for (int i = 1; i <= width; i++) {
				// Outputs * when first column and final column
				if (i == 1 || i == width)
					cout << "*";
				// Outputs nothing when middle column
				else
					cout << " ";
			}
			cout << endl;
		}
	}
}

void printWedge(int height) {
	cout << endl;

	// Outputs Wedge
	int count = 1;
	// Generate lines until reaching boxHeight
	for (int i = 0; i < height; i++) {
		// Outputs ** N times for each
		for (int i = 0; i < count; i += 2) {
			cout << "**";
		}
		count += 2;
		cout << endl;
	}
}