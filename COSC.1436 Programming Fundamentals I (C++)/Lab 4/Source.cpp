//
//	Name: Lawson Zeugin
//	Assignment: Program Four
//	Class: 1436.S03
//	Date: September 2016
//

#include <iostream>

using namespace std;

void main() {
	double i;
	double increasingSumD;
	float increasingSumF;
	double decreasingSumD;
	float decreasingSumF;

	i = 1;
	increasingSumD = 0;
	while (i < 100000000) {				// 1/1, 1/2, 1/3...1/99999997, 1/9999998 Using Double
		increasingSumD += (1 / i);
		i++;
	}

	i = 1;
	increasingSumF = 0;
	while (i < 100000000) {				// 1/1, 1/2, 1/3...1/99999997, 1/9999998 Using Double
		increasingSumF += (1 / i);
		i++;
	}

	i = 100000000;
	decreasingSumD = 0;
	while (i > 0) {
		decreasingSumD += (1 / i);
		i--;
	}

	i = 100000000;
	decreasingSumF = 0;
	while (i > 0) {
		decreasingSumF += (1 / i);
		i--;
	}

	cout << "Increasing Sum Double: " << increasingSumD << endl;
	cout << "Increasing Sum Float: " << increasingSumF << endl;
	cout << "Decreasing Sum Double: " << decreasingSumD << endl;
	cout << "Decreasing Sum Float: " << decreasingSumF << endl;
}