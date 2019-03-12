// Lawson Zeugin
// COSC 1436.S03
// Program Six
// September 2016

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string palindrome;
	bool end = false;

	while (end != true) {
		cout << "Please enter a string: ";
		cin >> palindrome;
		if (palindrome != "END") {
			if (palindrome == string(palindrome.rbegin(), palindrome.rend())) {
				cout << palindrome << " is a palindrome" << endl;
			}
			else {
				cout << palindrome << " is not a plaindrome" << endl;
			}
		}
		else {
			cout << "Shutting down..." << endl;
			end = true;
		}
	}
}