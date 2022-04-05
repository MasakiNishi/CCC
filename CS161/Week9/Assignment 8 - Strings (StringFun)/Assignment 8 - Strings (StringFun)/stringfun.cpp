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

int main() {
    int x = 0;
    if (x < 0)
        cout << "One ";
        cout << "Two ";
    cout << "Three";
}