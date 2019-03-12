//
//	Name: Lawson Zeugin
//	Assignment: Program Five - Calculator
//	Class: 1436.S03
//	Date: September 2016
//

#include <iostream>

using namespace std;

#include <ctype.h>
#include <stdlib.h>

void main() {
	char op;
	float numOne;
	float numTwo;
	float awn;
	int end = 1;

	cout << "Please Insert Your First Number: ";
	cin >> numOne;

	while (end == 1) {

		if (end == 1) {
			cout << "Please Insert Your Operation: ";
			cin >> op;

			switch (tolower(op)) {
			case 'x':	// Stops the program
				end = 0;
				cout << "Shutting Down..." << endl;
				break;

			case 'c':	// Clears memory and screen
				system("CLS");
				cout << "Please Insert Your First Number: ";
				cin >> numOne;
				break;

			case '+':	// Addition
				cout << "Please Insert Your Second Number: ";
				cin >> numTwo;
				awn = numOne + numTwo;
				numOne = awn;
				cout << endl << awn << endl << endl;
				break;

			case '-':	// Subtraction
				cout << "Please Insert Your Second Number: ";
				cin >> numTwo;
				awn = numOne - numTwo;
				numOne = awn;
				cout << endl << awn << endl << endl;
				break;

			case '/':	// Division
				cout << "Please Insert Your Second Number: ";
				cin >> numTwo;
				awn = numOne / numTwo;
				numOne = awn;
				cout << endl << awn << endl << endl;
				break;

			case '*':	// Multiplication
				cout << "Please Insert Your Second Number: ";
				cin >> numTwo;
				awn = numOne * numTwo;
				numOne = awn;
				cout << endl << awn << endl << endl;
				break;

			default:
				cout << endl << "ERROR: Please insert an actual operation (* / + -), 'x' to stop the program, or 'c' to clear the screen" << endl << endl;
				break;
			}
		}
	}
}