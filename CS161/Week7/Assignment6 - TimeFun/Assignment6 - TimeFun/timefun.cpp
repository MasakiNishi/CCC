/*
@file		Time Fun.cpp
@author		Masaki Nishi
@version	1.0
Converts times expressed in 24-hour format to 12-hour format using a.m. and p.m.
*/

#include <iostream> // required for cin/cout
#include <iomanip> // required for setfill/setw

using namespace std; // sets the default namespace to std for the program

// function prototypes

/*
Gets valid time(hourand minute) expressed as per 24 hour clock.
@param	int(hour), int(minute)
@return void
*/
void getTime24(int& hour, int& minute);

/*
Converts 24 - hour clock hour to 12 - hour clock hour
@param	int(hour), char(meridiem)
@return int - Hour in 12 hour format
*/
int convertTime24to12(int hour, char& meridiem);

/*
Prints the given time in 12 hour format
@param	int(hourIn12), int(minute), char(meridiem)
@return void
*/
void printTime12(int hourIn12, int minute, char meridiem);

/*
Prints the given time in 24 hour format
@param	int(hour), int(minute)
@return void
*/
void printTime24(int hour, int minute);

/*
Determines if user wants to continue.
@param	none
@return True or False depending on users action
*/
bool userWantsToContinue();

int main() {
	// Set reference parameters
	int hour;
	int minute;
	char meridiem;

	// Call functions to convert 24-hour format time to 12-hour format until user inputs N
	do {
		getTime24(hour, minute);
		int hourIn12 = convertTime24to12(hour, meridiem);
		printTime12(hourIn12, minute, meridiem);
		printTime24(hour, minute);
	} while (userWantsToContinue() == 1);
}

void getTime24(int& hour, int& minute) {
	// Gets 24-hour format
	char ch;
	cout << "Enter a time in 24 hour format (for example 13:45): ";
	cin >> hour >> ch >> minute;
	cin.ignore(100, '\n');

	// Continues to get proper 24-hour format time
	while (hour < 0 || hour > 24 || ch != ':' || minute < 0 || minute >= 60 || hour == 24 && minute > 0 ) {
		cout << "The format is incorrect : Try again : ";
		cin >> hour >> ch >> minute;
		cin.ignore(100, '\n');
	}
}

int convertTime24to12(int hour, char& meridiem) {
	// Return hour in 12-hour format and set meridiem
	// Return 12am When hour is 0
	if (hour == 0) {
		meridiem = 'a';
		return 12;
	}
	// Return hour am as it is if hour is less than 12
	else if(hour <= 12) {
		// Return pm when hour is 12
		if (hour == 12)
			meridiem = 'p';
		else
			meridiem = 'a';
		return hour;
	}
	// Return hour - 12 to convert 12-hour format if hour is more than 12
	else {
		// Return 12am if hour is 24
		if (hour == 24)
			meridiem = 'a';
		else
			meridiem = 'p';
		return hour - 12;
	}
}

void printTime12(int hourIn12, int minute, char meridiem) {
	// Outputs 12-hour format
	cout << "That time in 12 hour format is: " << hourIn12 << ":";
	// fill out with 0 for a minute if char length is 1
	cout << setfill('0') << right << setw(2) << minute << setfill(' ') << setw(0);
	cout << " " << meridiem << "m" << endl;
}

void printTime24(int hour, int minute) {
	// Outputs 24-hour format
	cout << "That time in 24 hour format is: ";
	// fill out with 0 for an hour and a minute if char length is 1
	cout << setfill('0') << right << setw(2) << hour << setfill(' ') << setw(0) << ":";
	cout << setfill('0') << right << setw(2) << minute << setfill(' ') << setw(0) << endl;
}

bool userWantsToContinue() {
	cout << endl;
	char again;

	// Gets Y or N to continue or to stop
	cout << "Would you like to continue (Y/N)? ";
	cin >> again;
	cin.ignore(100, '\n');

	// Continues to get proper char
	while (again != 'Y' && again != 'N') {
		cout << "That char is incorrect : Try again : ";
		cin >> again;
		cin.ignore(100, '\n');
	}

	cout << endl;

	// Return boolen and if true, continues to get 24-hour format from user to convert into 12-hour format
	if (again == 'Y')
		return true;
	else
		return false;
}
