//
//  main.cpp
//  Lab 6
//
//  Created by Lawson Zeugin on 4/20/17.
//  Copyright © 2017 Lawson Zeugin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void encrypt() {

	string fileName, encrypt;
	char ch;

	// Ask the user to enter the name of the unencrypted file
	cout << "What should I name the file where the encryption will be stored: ";
	cin >> fileName;
	cout << "What should I enter in the file: ";
	cin >> encrypt;

	fstream inFile(fileName, ios::in);
	if (!inFile)
	{
		cout << "ERROR: Cannot open \"" << fileName << "\".\n";
	}

	fstream outFile(encrypt, ios::out);

	while (!inFile.fail())
	{
		inFile.get(ch);
		ch += 10;
		outFile << ch;
	}

	inFile.close();
	outFile.close();
}

int decrypt() {
	string ecrypted, decrypt;
	char ch;

	// Ask user to enter the name of file to decrypt
	cout << "What file should I decrypt: ";
	cin >> ecrypted;

	fstream inFile(ecrypted, ios::in);
	if (!inFile)
	{
		cout << "ERROR: Cannot open file \"" << ecrypted << "\".\n";
	}

	cout << "Enter name for decrypted file: ";
	cin >> decrypt;
	fstream outFile(decrypt, ios::out);

	while (!inFile.fail())
	{
		inFile.get(ch);
		ch -= 10;
		outFile << ch;
	}

	inFile.close();
	outFile.close();
	return 0;
}

int main(int argc, const char * argv[]) {
	bool run = true;
	int choice = 0;

	do {
		cout << "WELCOME TO LAWSON'S SIMMPLE ENCRYPR/DECRYPT TOOL" << endl;
		cout << "\n\tPlease select an option from the menu below." << endl;
		cout << "/***********************************************\\" << endl;
		cout << " 1. Encrypt" << endl;
		cout << " 2. Decrypt" << endl;
		cout << " 3. Exit" << endl;
		cout << "\\***********************************************//" << endl;

		cout << "\nPlease select your option: ";
		cin >> choice;

		switch (choice) {
		case 1:
			// RUN ENCRYPT FUNCTION
			encrypt();
			break;
		case 2:
			// RUN DECRYPT FUNCTION
			decrypt();
			break;
		case 3:
			// EXIT
			run = false;
			break;

		default:
			cout << "ERROR: INVALID OPTION! PLEASE USE THE CORRESPONDING NUMBER TO THE CORRECT OPERATION!" << endl;
			break;
		}

	} while (run);


	return 0;
}
