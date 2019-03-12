#include <iostream>

using namespace std;

#include "theMath.h"

double add(double numOne, double numTwo, double & solution) {
	solution = numOne + numTwo;
	return solution;
}

double sub(double numOne, double numTwo, double & solution) {
	solution = numOne - numTwo;
	return solution;
}

double divide(double numOne, double numTwo, double & solution) {
	solution = (numOne) / (numTwo);
	return solution;
}

double mul(double numOne, double numTwo, double & solution) {
	solution = numOne * numTwo;
	return solution;
}