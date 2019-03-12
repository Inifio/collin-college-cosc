// Lawson Zeugin
// COSC-1436.S03
// Lab Twelve
// November 2016

#include <iostream>

using namespace std;

#include "readString.h"
#include "binarySearch.h"

void main() {
	const int maxNames(20);

	char * names[maxNames];
	char * pString;
	char * temp;
	char * search = "a";
	
	bool endInput = false;
	bool sorted = false;
	bool endSearch = false;

	int arrayAddress = 0;
	int addressCheck = 0;
	int enteredNames = 0;
	int i = 0;
	int index;
	int first;
	int middle;
	int last;

	do {	// Loop to read in names until the enter key is pressed
		cout << "Enter a name (Max 20): ";
		pString = readString();
		names[arrayAddress] = pString;
		enteredNames++;
		endInput = pString[0] == '\0';
		arrayAddress++;
	} while ((enteredNames < 20) && (!endInput));

	enteredNames--;

	cout << endl << "\tUnsorted Names" << endl;
	while (i != enteredNames) {
		cout << "Name " << i + 1 << ": " << names[i] << endl;
		i++;
	}



	do {	// Loop to bubble sort the read names
		sorted = true;
		for (i = 0; i < (enteredNames - 1); i++)
			if (strcmp(names[i], names[i + 1]) > 0) {
				temp = names[i];
				names[i] = names[i + 1];
				names[i + 1] = temp;
				sorted = false;
			}
			else;
	} while (!sorted);

	i = 0;
	cout << endl << "\tSorted Names" << endl;
	while (i != enteredNames) {
		cout << "Name " << i << ": " << names[i] << endl;
		i++;
	}
	
	/*cout << "What would you like to search for: ";
	cin >> search;

	first = 0;
	last = enteredNames;
	while (first <= last) {
		middle = (first + last) / 2;
		if (search == names[middle])
			cout << search << " has an index of " << middle << endl;
		else
			if (search < names[middle])
				last = middle - 1;
			else
				first = middle + 1;
	} */

	delete[] pString;	// Clear used dynamic memory
}