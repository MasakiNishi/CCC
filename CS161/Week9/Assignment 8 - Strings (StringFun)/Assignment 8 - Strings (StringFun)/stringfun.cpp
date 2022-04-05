/*
@file		String Fun.cpp
@author		Masaki Nishi
@version	1.0
C strings (null terminated array of chars) function to output users guessed my name.
C++ string datatype in place of the Cstring (char array) function to output users guessed my name.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // required for cin/cout
#include <cstring> // required for c-string functions like strcpy, strcmp, strlen, etc.
#include <string> // required to use string type

using namespace std; // sets the default namespace to std for the program

const int SIZE = 20;
const char MYNAME[] = "masaki nishi";

// function prototypes

/*
Prompt the user to guess my name, and outputs my correct my name with cstring type
@param	none
@return void
*/
void cStringDemo();

/*
Prompt the user to guess my name, and outputs my correct my name with string type
@param	none
@return void
*/
void stringTypeDemo();

/*
Returns a copy of the string with all the vowels removed
@param	char(user guessed name), char(my name without vowels)
@return void
*/
void removeVowels(const char* userGuessedName, char* myNameWithoutVowel);

/*
Returns a copy of the string with all the vowels removed
@param	string(user guessed name), string(my name without vowels)
@return void
*/
void removeVowels(string userGuessedName, string& myNameWithoutVowels);

int main() {
	// Call functions
	stringTypeDemo();
	cStringDemo();
}

void cStringDemo() {
	// declare some c-strings
	char userGuessedName[SIZE] = "";
	char myNameWithoutVowels[SIZE] = "";

	// Prompt the user to guess your name
	cout << "Guess my name (first last): ";
	cin.get(userGuessedName, SIZE); // can get a name up to 19 characters
	cout << endl;

	// Display a message saying whether or not the entered name matches your name
	if (strcmp(MYNAME, userGuessedName) == 0) {
		cout << "Nice, it's correct.";
	}
	else {
		cout << "Nice try, but incorrect.";
	}
	cout << endl << endl;

	// Outpus guessed name
	cout << "You guessed " << userGuessedName << endl;

	// Outputs guessed name with removed vowels
	removeVowels(userGuessedName, myNameWithoutVowels);
	cout << "Without vowels, that's " << myNameWithoutVowels << endl;
	cout << endl;

	// Sets and Outputs guessed name with the text “ the Barbarian”
	char barbarian[15] = " the Barbarian";
	char nameWithBarbarian[35];
	strcpy(nameWithBarbarian, userGuessedName);
	strcat(nameWithBarbarian, barbarian);
	cout << "And in less civilized times, it would be " << nameWithBarbarian << endl << endl;
}

void stringTypeDemo() {
	// declare some strings
	string userGuessedName;
	string myNameWithoutVowels;

	// Prompt the user to guess your name
	cout << "Guess my name (first last): ";
	getline(cin, userGuessedName);
	cout << endl;

	// Display a message saying whether or not the entered name matches your name
	if (userGuessedName == MYNAME) {
		cout << "Nice, it's correct.";
	}
	else {
		cout << "Nice try, but incorrect.";
	}
	cout << endl << endl;

	// Outpus guessed name
	cout << "You guessed " << userGuessedName << endl;

	// Outputs guessed name with removed vowels
	removeVowels(userGuessedName, myNameWithoutVowels);
	cout << "Without vowels, that's " << myNameWithoutVowels << endl;
	cout << endl;

	// Sets and Outputs guessed name with the text “ the Barbarian”
	string nameWithBarbarian = userGuessedName + " the Barbarian";
	cout << "And in less civilized times, it would be " << nameWithBarbarian << endl << endl;
}

void removeVowels(const char* userGuessedName, char* myNameWithoutVowels) {
	int count = 0;
	for (int i = 0; i < strlen(userGuessedName) - 1; i++) {
		if (userGuessedName[i] == 'a' || userGuessedName[i] == 'i' || userGuessedName[i] == 'u' || userGuessedName[i] == 'e' || userGuessedName[i] == 'o' ||
			userGuessedName[i] == 'A' || userGuessedName[i] == 'I' || userGuessedName[i] == 'U' || userGuessedName[i] == 'E' || userGuessedName[i] == 'O')
		{
		}
		else {
			myNameWithoutVowels[count] = userGuessedName[i];
			count++;
		}
	}
}

void removeVowels(string userGuessedName, string& myNameWithoutVowels) {
	for (int i = 0; i < userGuessedName.length() - 1; i++) {
		if (userGuessedName[i] == 'a' || userGuessedName[i] == 'i' || userGuessedName[i] == 'u' || userGuessedName[i] == 'e' || userGuessedName[i] == 'o' ||
			userGuessedName[i] == 'A' || userGuessedName[i] == 'I' || userGuessedName[i] == 'U' || userGuessedName[i] == 'E' || userGuessedName[i] == 'O')
		{
		}
		else {
			myNameWithoutVowels += userGuessedName[i];
		}
	}
}