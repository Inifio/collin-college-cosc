#include <iostream>

using namespace std;

#include <ctype.h>
#include <memory.h>

#include "ReadString.h"

char * ReadString()
{
	const	int		FirstGuess(50);
	char	c;
	int		CurrNumChars;
	int		CurrSize;
	char *	pString;
	char *	pTempString;

	CurrNumChars = 0;
	CurrSize = FirstGuess;
	pString = new char[CurrSize + 1];
	SkipSpaces();
	while (!isspace(c = cin.get()))
	{
		pString[CurrNumChars++] = c;
		if (CurrNumChars >= CurrSize)
		{
			CurrSize += FirstGuess;
			pTempString = new char[CurrSize + 1];
			memcpy(pTempString, pString, CurrNumChars);
			delete[] pString;
			pString = pTempString;
		}
		else;
	}
	pString[CurrNumChars] = '\0';
	return pString;
}

void SkipSpaces()
{
	char	c;

	while (isspace(c = cin.get()));
	cin.putback(c);
}