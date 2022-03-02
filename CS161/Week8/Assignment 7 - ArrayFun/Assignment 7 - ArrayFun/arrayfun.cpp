/*
@file		Array Fun.cpp
@author		Masaki Nishi
@version	1.0
Gets 10 integers from the user, stores them in an array, and then prints out:
the entire array
the lowest value in the array
the highest value in the array
the number of odd numbers in the array
the sum of all the values in the array.
all the values that appear in the array more than once
*/

#include <iostream> // required for cin/cout
#include <string> // required to use string type
#include <algorithm>  // required to use uniq
#include <vector> // required to use size and uniq

using namespace std; // sets the default namespace to std for the program

const int SIZE = 10;

// function prototypes

/*
Gets array with data entered by the user
@param	int(the array entered by the user), int(the array size)
@return void
*/
void getData(int data[], int size);

/*
Prints given array values to the screen(space delimited)
@param	int(the array to print), int(the array size), string(outputs message)
@return void
*/
void printData(const int array[], int size, string message);

/*
Returns the lowest value in the given array
@param	int(the array entered by the user), int(the array size)
@return int(lowest value in the array)
*/
int lowestValue(int data[], int size);

/*
Returns the highest value in the given array
@param	int(the array entered by the user), int(the array size)
@return int(highest value in the array)
*/
int highestValue(int data[], int size);

/*
Returns the number of odd numbers in the given array
@param	int(the array entered by the user), int(the array size)
@return int(number of odds in the array)
*/
int countOdds(int data[], int size);

/*
Returns the sum of all the values in the given array
@param	int(the array entered by the user), int(the array size)
@return int(sum of the array)
*/
int sum(int data[], int size);

/*
Returns duplicate values in the given array
@param	int(the array entered by the user), int(the array to output), int(the array size)
@return int(size of the output array)
*/
int getDuplicateValues(int data[], int duplicates[], int size);

int main() {
	// Set array
	int data[SIZE];
	int duplicates[SIZE];

	// Call functions
	getData(data, SIZE);

	int outputsLowestValue[] = { lowestValue(data, SIZE) };
	printData(outputsLowestValue, 1, "Lowest value: ");

	int outputsHighestValue[] = { highestValue(data, SIZE) };
	printData(outputsHighestValue, 1, "Highest value: ");

	int outputsOdds[] = { countOdds(data, SIZE) };
	printData(outputsOdds, 1, "# odd numbers: ");

	int outputsSum[] = { sum(data, SIZE) };
	printData(outputsSum, 1, "Sum of all: ");

	int duplicateCounts = getDuplicateValues(data, duplicates, SIZE);
	if (duplicateCounts > 0)
		printData(duplicates, duplicateCounts, "The following numbers appear multiple times: ");
}

void getData(int data[], int size) {
	cout << "Enter 10 integers (separated by a space): ";
	// loop over every valid array index
	for (int index = 0; index < size; index++) {
		// initialize the array with user inputted data
		cin >> data[index];
	}
	cout << endl;

	// outputs entered data
	cout << "\tYou entered : ";
	for (int index = 0; index < size; index++) {
		cout << data[index] << " ";
	}
	cout << endl << endl;
}

void printData(const int array[], int size, string message) {
	// loop over every valid array index and outputs the value
	cout << "\t" << message;
	for (int index = 0; index < size; index++) {
		cout << array[index] << ' ';
	}
	cout << endl;
}

int lowestValue(int data[], int size) {
	int min = data[0];
	// search num in inputArray from index 0 to size-1 
	for (int index = 0; index < size; index++) {
		if (data[index] < min) {
			min = data[index];
		}
	}

	return min;
}

int highestValue(int data[], int size) {
	int max = data[0];
	// search num in inputArray from index 0 to size-1 
	for (int index = 0; index < size; index++) {
		if (data[index] > max) {
			max = data[index];
		}
	}

	return max;
}

int countOdds(int data[], int size) {
	int odds = 0;
	// search num in inputArray from index 0 to size-1 
	for (int index = 0; index < size; index++) {
		if (data[index] % 2 == 0) {
			odds++;
		}
	}

	return odds;
}

int sum(int data[], int size) {
	int sum = 0;
	// search num in inputArray from index 0 to size-1
	for (int index = 0; index < size; index++) {
		sum = sum + data[index];
	}

	return sum;
}

int getDuplicateValues(int data[], int duplicates[], int size) {
	int count = 0;
	// search num in inputArray from index 0 to size-1
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			// set array and the size when a duplicate number found
			if (data[i] == data[j]) {
				count++;
				duplicates[count - 1] = data[i];
			}
		}
	}

	return count;
}
