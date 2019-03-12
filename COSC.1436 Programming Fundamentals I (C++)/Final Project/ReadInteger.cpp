#include <iostream>

using namespace std;

#include "ReadInteger.h"
#include "ReadString.h"

int ReadInteger()
{
	char	c;					// Variables declared inside a function are known as "local"
	int		Num;				// they can only be used inside this function
	int		NumCharsEntered;	// they are destroyed when the function finishes and are recreated
	bool	IsNeg;				// when the function starts up again

	IsNeg = false;
	Num = 0;
	NumCharsEntered = 0;
	SkipSpaces();
	while (!isspace(c = cin.get()))
	{
		switch (c)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			Num = (Num * 10) + (c - '0');
			NumCharsEntered++;
			break;
		default:;
		}
	}
	return Num;
}