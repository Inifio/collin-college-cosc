#include <iostream>
#include<string>

using namespace std;

#include "Plane.h"

void Fly (Planes ThisPlane, Plane & This, Plane & Lounge)
	{
	int i;
	int j;
	int z;
	int l = 0;
	int a;
	string name;

	switch (This.Parties[0].WhichPlane)
	{
	case 0:
		name = "Alfa";
		break;
	case 1:
		name = "Bravo";
		break;
	default:
		break;
	}
		cout << "\nParties on this flight.." << endl;
		for (z = 0; z < This.NumParties; z++)
		{
			cout << endl << This.Parties[z].Name << " party of " << This.Parties[z].Size << ". ABOARD" << endl;
		}
		This.NumEmptySeats = This.NumSeats;
		This.NumParties = 0;
		a = 0;
		delete[] This.Parties;
		This.Parties = new Party[This.NumSeats];
		if (Lounge.NumParties == 0)
		{
			cout << "\nFlight Complete." << endl;
		}
		cout << "\n" << name << " has landed, loading lounge." << endl;

		for (i = 0; i < Lounge.NumParties; i++) {
			if ((Lounge.Parties[i].WhichPlane == ThisPlane) && (Lounge.Parties[i].Size <= This.NumEmptySeats)) {	// Makes sure current person in queue is boarding this plane and if there is enough room for them
				This.NumEmptySeats = This.NumEmptySeats - Lounge.Parties[i].Size;									// Decreases the avilable seats left on the plane.
				This.NumParties++;																					// Increases the counter for partires aboard.
				This.Parties[a] = Lounge.Parties[i];																// Puts a party in the lounge on this plane
				cout << "\nAdded party " << This.Parties[a].Name << " of " << This.Parties[a].Size << endl;
				a++;
				for (j = i; j < Lounge.NumParties; j++) {															// Loop to bring everything up in the array
					Lounge.Parties[j] = Lounge.Parties[j + 1];
				}
				Lounge.NumParties--;																				// Decreases the parties waiting in the lounge.
				Lounge.NumEmptySeats = Lounge.NumEmptySeats - Lounge.Parties[i].Size;								// Opens up avilable seats in the lounge.
			}
		}

		if (This.NumEmptySeats == 0) {
			cout << "The lounge filled the plane, taking off again." << endl;
			Fly(ThisPlane, This, Lounge);
		}
		else {
			cout << "\nThe flight command has completed. There are " << This.NumEmptySeats << " empty seats left on " << name << endl;
		}
}
