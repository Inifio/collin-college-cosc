#include <conio.h>

#include "readInt.h"

int readInteger()
{
	char	c;					// Variables declared inside a function are known as "local"
	int		Num;				// they can only be used inside this function
	int		NumCharsEntered;	// they are destroyed when the function finishes and are recreated
	bool	IsNeg;				// when the function starts up again

	IsNeg = false;
	Num = 0;
	NumCharsEntered = 0;
	while ((c = _getch()) != '\r')	// _getch reads one character from the keyboard but does not show it on screen
	{							// _getch uses \r for the enter key, not \n
		switch (c)
		{
		case '-':
			if (NumCharsEntered == 0)
			{
				IsNeg = true;
				NumCharsEntered++;
			}
			else
				c = '\a';
			break;
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
		case '\b':		// backspace
			if (NumCharsEntered > 0)
			{
				Num = Num / 10;
				NumCharsEntered--;
				if (NumCharsEntered == 0)
					IsNeg = false;
				else;
				_putch('\b');
				_putch(' ');
			}
			else
				c = '\a';
			break;
		default:
			c = '\a';
		}
		_putch(c);
	}
	_putch('\n');
	if (IsNeg)
		Num = -Num;
	else;
	return Num;
}