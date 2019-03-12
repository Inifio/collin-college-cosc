//////////////////////////////////
//	Name: Lawson Zeugin
//	Class: 
//	Assignment:
//	Date:
/////////////////////////////////

#include <iostream>
using namespace std;

void main() {
	int numOne;
	int numTwo;

	cout << "Please insert a number: ";
	cin >> numOne;

	cout << "Please insert another number: ";
	cin >> numTwo;

	if (numOne > numTwo) {
		cout << numOne << " is greater than " << numTwo << endl;
	}
	else if (numOne < numTwo) {
		cout << numOne << " is less than " << numTwo << endl;
	}
	else if (numOne == numTwo) {
		cout << numOne << " and " << numTwo << " are equal to each other" << endl;
	}

	if ((numOne < 0) && (numTwo < 0)) {
		cout << "Both " << numOne << " and " << numTwo << " are negative" << endl;
	}
	else if ((numOne > 0) && (numTwo > 0)) {
		cout << "Both " << numOne << " and " << numTwo << " are positive" << endl;
	}
	else if (numOne < 0) {
		cout << numOne << " is negative, while " << numTwo << " is positive" << endl;
	}
	else if (numTwo < 0) {
		cout << numOne << " is positive, while " << numTwo << " is negative" << endl;
	} else if ((numOne > 0) && (numTwo > 0)) {

	}

	int numThree;

	cout << "Please insert a third number: ";
	cin >> numThree;

	switch (numThree)
	{
	case 1: cout << "ONE" << endl;
		break;
	case 2:  cout << "TWO" << endl;
		break;
	case 3: cout << "THREE" << endl;
		break;
	case 4: cout << "FOUR" << endl;
		break;
	case 5: cout << "FIVE" << endl;
		break;
	case 6: cout << "SIX" << endl;
		break;
	case 7: cout << "SEVEN" << endl;
		break;
	case 8: cout << "EIGHT" << endl;
		break;
	case 9: cout << "NINE" << endl;
		break;
	default:	cout << "Error: Out of Range" << endl;
		break;
	}
}