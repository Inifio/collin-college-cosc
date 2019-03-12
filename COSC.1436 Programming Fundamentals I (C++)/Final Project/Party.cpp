#include <string.h>

#include "Party.h"
#include "ReadString.h"

char *	PlaneWords[] = {
	"Alfa",
	"Bravo"
};

Planes ReadPlane()
{
	char *	WhichPlane;
	Planes	Plane;

	WhichPlane = ReadString();
	for (Plane = PlaneAlfa; Plane < PlaneBad; Plane = (Planes)(Plane + 1))
		if (_strcmpi(WhichPlane, PlaneWords[Plane]) == 0)
		{
			delete[] WhichPlane;
			return Plane;
		}
		else;
		delete[] WhichPlane;
		return PlaneBad;
}