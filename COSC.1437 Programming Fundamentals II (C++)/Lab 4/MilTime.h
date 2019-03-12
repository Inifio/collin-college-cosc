// Specification file for the MilTime class
#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

// Declaration of the MilTime class

class MilTime : public Time
{
private:
	int milHours;
    int milSeconds;
public:
	MilTime(int, int);

    void convert();

	void setTime(int, int);

    int getHour() 
		{ return milHours; }

    int getStandHr() 
		{ return hour; }
};

#endif