/*
@file		Data Fun.cpp
@author		Masaki Nishi
@version	1.0
This file is to evaluate conditions of intergers and characters

---Here is pseudocode of part1 below---
cin user’s favorite integer
cin.ignore

If users_favorite_integer is positive including 0
	cout positive
else if it is negative
	cout negative

if users_favorite_integer is more than 1000
	cout greter than 1000
else if users_favorite_integer is more than 100
	cout greter than 100
else more than 10
	cout greter than 10

if users_favorite_integer is even (% 2 == 0)
	cout it is even
else it is odd
	cout it is odd

switch users_favorite_integer is
case 2
	cout this is Helium
case 10
	cout this is Neon
case 18
	cout this is Argon
case 36
	cout this is Krypton
case 54
	cout this is Xenon
case 86
	cout this is Radon
case 118
	cout this is Oganesson
default
	not noble gas

---Here is pseudocode of part2 below---
cin users_favorite_character
cin.ignore

if its a digit
	cout its numeric digit
} else {
	if lowercase letter
		cout its lowercase
	else uppercase
		cout uppercase

	if its a vowel
		cout its vowel
	else
		cout not vowel

	char_ascii =  ASCII value with static_cast<int>
	cout ASCII is char_ascii
	char_num = char_ascii - 25
	
	switch char_num
	case 1
		cout its char_num st
	case 2
		cout its char_num nd
	case 3
		cout its char_num rd
	default
		cout its char_num th
}
*/

#include <iostream> // required for cin/cout

using namespace std; // sets the default namespace to std for the program

int main() {
	// Get a Integer from the user
	int usersInt;
	cout << "Please enter your favorite integer: ";
	cin >> usersInt;
	cin.ignore(100, '\n');

	// Evaluate integer and Output the results
	cout << endl;
	cout << "What is your favorite integer? " << usersInt << endl;

	// Print out if it’s positive or negative (consider 0 as positive)
	if (usersInt >= 0)
		cout << "\t" << usersInt << " is a positive number," << endl;
	else
		cout << "\t" << usersInt << " is a negative number," << endl;

	// Print out if it’s greater than 10, 100, or 1000 (only print the highest one it’s greater than).
	if (usersInt > 1000)
		cout << "\tit is greater than 1000," << endl;
	else if (usersInt > 100)
		cout << "\tit is greater than 100," << endl;
	else if (usersInt > 10)
		cout << "\tit is greater than 10," << endl;
	else
		cout << "\tit is less than 10," << endl;

	// Print out if it’s odd or even 
	if (usersInt % 2 == 0)
		cout << "\tit is even," << endl;
	else
		cout << "\tit is odd," << endl;

	// Output the name of the atomic if the number is the atomic number of one of the 7 noble gases
	switch (usersInt) {
	case 2:
		cout << "\tand it is the atomic number of a Helium." << endl;
		break;
	case 10:
		cout << "\tand it is the atomic number of a Neon." << endl;
		break;
	case 18:
		cout << "\tand it is the atomic number of a Argon." << endl;
		break;
	case 36:
		cout << "\tand it is the atomic number of a Krypton." << endl;
		break;
	case 54:
		cout << "\tand it is the atomic number of a Xenon." << endl;
		break;
	case 86:
		cout << "\tand it is the atomic number of a Radon." << endl;
		break;
	case 118:
		cout << "\tand it is the atomic number of a Oganesson." << endl;
		break;
	default:
		cout << "\tand it is not the atomic number of a noble gas." << endl;
		break;
	}

	// Get a Character from the user
	char usersChar;
	cout << endl;
	cout << "Please enter your favorite character: ";
	cin >> usersChar;
	cin.ignore(100, '\n');

	// Evaluate character and Output the results
	cout << endl;
	cout << "What is your favorite character? " << usersChar << endl;

	// Print out if it’s a numeric digit or letter
	if ('0' <= usersChar && usersChar <= '9') {
		cout << "\tit is a numeric digit" << endl;
	} else {
		// Set ASCII number of char to output ASCII value and alphabet's number order
		int asciiNum = static_cast<int>(usersChar);
		int charNum;
		
		// Print out if its lowercase or uppercase and set charNum for alphabet's number order
		if ('a' <= usersChar && usersChar <= 'z') {
			cout << "\t" << usersChar << " is a lowercase letter," << endl;
			charNum = asciiNum - 96;
		} else {
			cout << "\t" << usersChar << " is an uppercase letter," << endl;
			charNum = asciiNum - 64;
		}

		// Prints out if it’s a vowel or not
		if (usersChar == 'a' || usersChar == 'i' || usersChar == 'u' || usersChar == 'e' || usersChar == 'o' ||
			usersChar == 'A' || usersChar == 'I' || usersChar == 'U' || usersChar == 'E' || usersChar == 'O')
			cout << "\t" << "it is a vowel," << endl;

		// Prints out ASCII value
		cout << "\t" << "its ASCII value is " << asciiNum << "," << endl;

		// Prints out alphabet's number order
		switch (charNum) {
		case 1:
		case 11:
		case 21:
			cout << "\t" << "and it is the " << charNum << "st letter of the alphabet." << endl;
			break;
		case 2:
		case 12:
		case 22:
			cout << "\t" << "and it is the " << charNum << "nd letter of the alphabet." << endl;
			break;
		case 3:
		case 13:
		case 23:
			cout << "\t" << "and it is the " << charNum << "ed letter of the alphabet." << endl;
			break;
		default:
			cout << "\t" << "and it is the " << charNum << "th letter of the alphabet." << endl;
		}
	}
	return 0;
}