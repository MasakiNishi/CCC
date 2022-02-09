/*
@file		Loop Fun.cpp
@author		Masaki Nishi
@version	1.0

Get two integer values (a box height and width) from the user.
Print out all the numbers between the height and width, and then print the average of those numbers.
Print rectangle using the height and width and triangle using the height.
*/

#include <iostream> // required for cin/cout

using namespace std; // sets the default namespace to std for the program

int main() {
	// Set a box integer
	int boxHeight;
	int boxWidth;
	// Set count to make easier for a loop function
	int count = 0;
	// Set average between the height and width
	float averageNum = 0.f;

	// Get a boxHeight from the user
	cout << "Enter a box height(between 3 and 10): ";
	cin >> boxHeight;
	cin.ignore(100, '\n');

	// Continues to get proper Integer (between 3 to 10)
	while (boxHeight < 3 || 10 < boxHeight) {
		cout << "That number is out of bounds : Try again : ";
		cin >> boxHeight;
		cin.ignore(100, '\n');
	}

	// Get a boxWidth from the user
	cout << endl;
	cout << "Enter a box width between (" << boxHeight + 1 << " and 20): ";
	cin >> boxWidth;
	cin.ignore(100, '\n');
	
	// Continues to get proper Integer (between boxHeight + 1 to 20)
	while (boxWidth < (boxHeight + 1) || 20 < boxWidth) {
		cout << "That number is out of bounds : Try again : ";
		cin >> boxWidth;
		cin.ignore(100, '\n');
	}

	// Outputs all numers between the height and width
	cout << endl;
	cout << "The integers from " << boxHeight << " to " << boxWidth << " are:" << endl;
	cout << "\t";
	for (int i = boxHeight; i <= boxWidth; i++) {
		// Set a sum and count numbers between the height and width to calculate average
		count += 1;
		averageNum += i;

		cout << i << " ";
	}
	// Outputs average between the height and width
	cout << endl;
	averageNum = averageNum / count;
	cout << "and the average of those numbers is " << averageNum << endl;

	// Outputs ractangle
	cout << endl;
	for (int i = 1; i <= boxHeight; i++) {
		// When first line and final line
		if (i == 1 || i == boxHeight) {
			// Outputs * until reaching boxWidth
			for (int i = 1; i <= boxWidth; i++) {
				cout << "*";
			}
			cout << endl;
		// When middle line
		} else {
			for (int i = 1; i <= boxWidth; i++) {
				// Outputs * when firsl column and final column
				if (i == 1 || i == boxWidth)
					cout << "*";
				// Outputs nothing when middle column
				else
					cout << " ";
			}
			cout << endl;
		}
	}

	// Outputs triangle
	cout << endl;
	count = 1;
	// Generate lines until reaching boxHeight
	for (int i = 0; i < boxHeight; i++) {
		// Outputs ** N times for each
		for (int i = 0; i < count; i += 2) {
			cout << "**";
		}
		count += 2;
		cout << endl;
	}
	return 0;
}