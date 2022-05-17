/** ---------------------------
* @file		LinkedListDemo.cpp
* @author	Masaki Nishi
* @version	1.0
*
* CS162-01 - Assignment 4.1
*	Implements a demo for the LinkedList class.
*
* --------------------------- */

#include <fstream>
#include <iterator>
#include "LinkedList.h"

int main() {

	LinkedList linkedTest;

	std::ifstream file("linkListTest.txt");
	std::string string;
	char i;

	while (file >> i) {
		switch (i) {
		// Add the string to the list
		case 'a':
			file >> string;
			if (linkedTest.insert(string)) {
				std::cout << "Added " << string << std::endl;
			}
			else {
				std::cout << string << " cannot be added again" << std::endl;
			}
			break;
		// Remove the string from the list
		case 'r':
			file >> string;
			if (linkedTest.remove(string)) {
				std::cout << "Removing " << string << std::endl;
			}
			else {
				std::cout << "Can't remove " << string << std::endl;
			}
			break;
		// Print how many strings are in the list and the list of strings (followed by a blank line)
		case 'P':
			if (linkedTest.count() == 1) {
				std::cout << "List contains " << linkedTest.count() << " name: ";
			}
			else {
				std::cout << "List contains " << linkedTest.count() << " names: ";
			}
			linkedTest.print();
			std::cout << std::endl;
			break;
		// Find the name is the list
		case 'f':
			file >> string;
			if (linkedTest.find(string) != 0) {
				std::cout << string << " is at position " << linkedTest.find(string) << std::endl;
			}
			else {
				std::cout << string << " is not in the list" << std::endl;
			}
			break;
		// Remove all entries from the list
		case 'R':
			linkedTest.removeAll();
			std::cout << "Removing all entries" << std::endl;
			break;
		default:
			file >> string;
			std::cout << "Nothing happened" << std::endl;
		}
	}
}