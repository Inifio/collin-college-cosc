#ifndef PARTY_H
#define PARTY_H

enum Planes {
	PlaneAlfa,
	PlaneBravo,

	PlaneBad
};

struct Party
{
	size_t		Size;
	Planes		WhichPlane;
	char *		Name;
};

Planes ReadPlane();

#endif