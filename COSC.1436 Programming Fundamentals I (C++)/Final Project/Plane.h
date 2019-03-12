#ifndef PLANE_H
#define PLANE_H

#include "Party.h"

struct Plane
{
	size_t		NumSeats;
	size_t		NumEmptySeats;
	size_t		NumParties;
	Party *		Parties;
};

void Fly(Planes ThisPlane, Plane & This, Plane & Lounge);

//void flyAway(Party AlfaParty, Party LoungeParty, Plane ThisPlane);

#endif