// Lawson Zeugin
// COSC-1436.S03
// Lab Ten
// October 2016

#include <iostream>

using namespace std;

#include "readInt.h"

void main() {
	int i;
	int enteredNum;
	int num[20];
	int temp;

	bool sorted;

	cout << "How many number would you like to insert? ";
	enteredNum = readInteger();

	for (i = 0; i < enteredNum; i++) {
		cout << "\n Number " << i + 1 << ": ";
		num[i] = readInteger();
	}

	cout << "\n\tUnsorted Numbers" << endl;
	for (i = 0; i < enteredNum; i++) {
		cout << i + 1 << ") " << num[i] << endl;
	}

	do {
		sorted = true;
		for (i = 0; i < (enteredNum - 1); i++) {
			if (num[i] > num[i + 1]) {
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
				sorted = false;
			}
		}
	} while (!sorted);

	cout << "\n\tSorted Numbers" << endl;
	for (i = 0; i < enteredNum; i++) {
		cout << i + 1 << ") " << num[i] << endl;
	}
}