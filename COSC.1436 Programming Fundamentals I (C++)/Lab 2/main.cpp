//***************************************
//
//	Name: Lawson Zeugin
//	Assignment: Program exercise two; math and numbers
//	Class: COSC 1436.S03
//	Date: August 2016
//
//***************************************

#include <iostream>

using namespace std;

void main() {

	cout << "=============== Whole Numbers ===============";

	cout << endl;

	// Ask user for two whole numbers
	int num1;
	int num2;
	cout << "Please insert two whole numbers\n" << endl << "First number: ";
	cin >> num1;
	cout << "Second number: ";
	cin >> num2;

	cout << endl;	// Display the two chosen numbers

	cout << "You chose, " << num1 << " as your first number, and " << num2 << " as your second." << endl;

	cout << endl;	// Add the two numbers

	int sum;
	sum = num1 + num2;
	cout << "The sum of your two numbers is: " << sum << endl;

	cout << endl;	// Divide the two numbers

	int div;
	div = num1 / num2;
	cout << "The quotient of the two numbers is: " << div << endl;

	cout << endl;	// Find the remainder of the two numbers

	int remain;
	remain = num1 % num2;
	cout << "The remainder of the first number divided by the second is: " << remain << endl;

	cout << endl;	// Multiply the two numbers

	int product;
	product = num1 * num2;
	cout << "The product of the two numbers is: " << product << endl;

	cout << endl;	// Subtract the two numbers

	int dif;
	dif = num1 - num2;
	cout << "The difference of the two numbers is: " << dif << endl;

	cout << endl;

	cout << "============================================" << endl;

	cout << endl;

	cout << "=============== Fractional Numbers ===============" << endl;

	// Determining float variables
	float fracNum1;
	float fracNum2;

	// Asking the user for two fractional numbers
	cout << "Please insert two fractional numbers.\n" << endl << "First number: ";
	cin >> fracNum1;
	cout << "Second number: ";
	cin >> fracNum2;

	cout << endl;	// Show the user the two numbers

	cout << "You chose, " << fracNum1 << " as your first number, and " << fracNum2 << " as your second." << endl;

	cout << endl;	// Sum of the two numbers

	float fracSum;
	fracSum = fracNum1 + fracNum2;
	cout << "The sum of the two numbers is: " << fracSum << endl;

	cout << endl;	// Divide the two numbers

	float fracDiv;
	fracDiv = fracNum1 / fracNum2;
	cout << "The quotient of the two numbers is: " << fracDiv << endl;

	cout << endl;	// Multiply the two numbers

	float fracProduct;
	fracProduct = fracNum1*fracNum2;
	cout << "The two numbers multiplyed is: " << fracProduct << endl;

	cout << endl;	// Subtract the two numbers

	float fracDiff;
	fracDiff = fracNum1 - fracNum2;
	cout << "The difference between the two numbers is: " << fracDiff << endl;

	cout << endl << "==================================================" << endl << endl;
}