//Example - default namespace
//We can provide a "default" namespace that the compiler will use when looking for the definitions of things.
//Note: namespaces aren't discussed until chapter 8, but knowing a little now will save us some typing.
#include <iostream> //for console I/O (cin and cout)  

using namespace std;

int main() {
	int x;
	int y;

	// get user input  
	cout << "Enter an integer: ";
	cin >> x;

	// compute and print output  
	y = x * 2;
	cout << x << " doubled is " << y;

	return 1;
}

//Example - include file
//Some programs want will read from or write to a console window.In order to tell the compiler about the items necessary for that functionality, the programmer must include the <iostream>(Input / Output Stream) header file.
//During the build process, the pre - processor will get that file from disk and "copy and paste" its entire contents in place of the "#include <iostream>" statement.
//#include <iostream> //for console I/O (cin and cout)  
//
//int main() {
//	int x;
//	int y;
//
//	// get user input  
//	std::cout << "Enter an integer: ";
//	std::cin >> x;
//
//	// compute and print output  
//	y = x * 2;
//	std::cout << x << " doubled is " << y;
//
//	return 1;
//}
//
//Example - No Include file
//The code below uses only stuff that is so common it's always available (no include file necessary).
//int main() {
//	int x;        //declare an integer variable named x  
//	x = 4 + 2;    //add 4 and 2 and put the results in x  
//
//	return 1;     //return the value 1 to the operating system  
//}