/** ---------------------------
* @file		LinkedList.cpp
* @author	Masaki Nishi
* @version	1.0
*
* CS162-01 - Assignment 4.1
*	Implements the LinkedList class.
*
* --------------------------- */

#include "LinkedList.h"

// --------------------------- 
LinkedList::LinkedList() {
	head = nullptr;
};

// --------------------------- 
LinkedList::~LinkedList() {
	removeAll();
}

// --------------------------- 
bool LinkedList::insert(std::string str) {
	bool hasAddedItem = false;
	Node* current = head;
	Node* previous = nullptr;

	// If there are no nodes
	if (head == nullptr) {
		head = new Node{ str, nullptr };
		return true;
	}

	while (current != nullptr) {
		// If the strings are duplicating
		if (str.compare(current->data) == 0) {
			return false;
		}

		if (str.compare(current->data) < 0) {
			if (previous) {
				previous->next = new Node { .data = str, .next = current };
			}
			else {
				head = new Node { .data = str, .next = current };
			}
			return true;
		}
		previous = current;
		current = current->next;
	}

	previous->next = new Node { .data = str, .next = nullptr };

	return true;
}

// --------------------------- 
bool LinkedList::remove(std::string str) {
	Node* current = head;
	Node* previous = nullptr;

	while (current != nullptr) {
		if (str.compare(current->data) == 0) {
			if (previous) {
				previous->next = current->next;
			}
			else {
				head = current->next;
			}
			delete current;
			return true;
		}

		previous = current;
		current = current->next;
	}

	return false;
}

// --------------------------- 
void LinkedList::print() {
	Node* current = head;
	while (current != nullptr) {
		std::cout << current->data;

		if (current->next != nullptr) {
			std::cout << ", ";
		}

		current = current->next;
	}
}

// --------------------------- 
int LinkedList::count() {
	int count = 0;
	Node* current = head;

	while (current != nullptr) {
		count = count += 1;

		current = current->next;
	}

	return count;
}

// --------------------------- 
int LinkedList::find(std::string str) {
	int position = 0;
	Node* current = head;
	while (current != nullptr) {
		position += 1;

		if (str.compare(current->data) == 0) {
			return position;
		}

		current = current->next;
	}
	return 0;
}

// --------------------------- 
void LinkedList::removeAll() {
	Node* current = head;

	while (current != nullptr) {
		Node* next = current->next;
		delete current;

		if (!next) {
			head = nullptr;
		}

		current = next;
	}
}