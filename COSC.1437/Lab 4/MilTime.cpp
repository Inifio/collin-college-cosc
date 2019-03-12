// Implmentation file for the MilTime class
#include <iostream>
#include "MilTime.h"
using namespace std;

//***********************************************
// Constructor                                  *
//***********************************************

MilTime::MilTime(int s = 0, int h = 0) : Time(0, 0, s)
{
	if (h < 0 || h > 2359)
	{
		throw;
	}
	else if (s < 0 || s > 59)
	{
		throw;
	}
	else
	{
		milHours = h;
   	    milSeconds = s;
	}
	convert();
}

//***********************************************
// convert member function                      *
//***********************************************

void MilTime::convert()
{
	double temp;

	if (milHours > 1200)
		hour = milHours - 1200;
	else
		hour = milHours;
	
	hour /= 100;
	temp = (milHours - 1200) / 100.0;
	min = static_cast<int>(((temp - static_cast<int>(temp)) * 100));
}

//***********************************************
// setTime member function                      *
//***********************************************

void MilTime::setTime(int h, int s)
{
	milHours = h;
	milSeconds = s;
	convert();
}
