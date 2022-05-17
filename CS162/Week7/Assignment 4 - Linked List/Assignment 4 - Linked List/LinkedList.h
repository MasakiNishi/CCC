/** ---------------------------
* @file		LinkedList.h
* @author	Masaki Nishi
* @version	1.0
*
* CS162-01 - Assignment 4.1
*	Implements a linked list.
*
* --------------------------- */

#pragma once

#include <iostream>
#include <string>

struct Node {
	std::string data;
	Node* next;
};

class LinkedList {
	public:
		/**
		*	Initializes a LinkedList with the head set to a Node object
		*/
		LinkedList();

		/**
		*	Deletes all the Node()s in the list
		*/
		~LinkedList();

		/**
		*	Inserts a new string in the nodes in alphabetical order without dupulicates
		*		@param str - the string to insert
		*		@return true or false by results
		*/
		bool insert(std::string str);

		/**
		*	Removes a string from the nodes
		*		@param str - the string to remove
		*		@return true or false by results
		*/
		bool remove(std::string str);

		/**
		*	Prints the value of all nodes
		*/
		void print();

		/**
		*	Returns the number of nodes in the list.
		*		@return the number of nodes in the list
		*/
		int count();

		/**
		*	Finds a string's position in the nodes
		*		@param str - the string to find
		*		@return the string's position in the nodes, 0 if the string can't be found.
		*/
		int find(std::string str);

		/**
		*	Removes all nodes in the list.
		*/
		void removeAll();

	private:
		Node* head;
};