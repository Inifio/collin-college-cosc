#include <iostream>

using namespace std;

#include "ReadInteger.h"
#include "ReadString.h"
#include "Plane.h"
#include "Party.h"
#include "Commands.h"

void main() {
	Commands menuOption;

	bool InitAlfa = false;
	bool InitBravo = false;
	bool InitLounge = false;
	bool shutdown = false;

	Plane Alfa;
	Plane Bravo;
	Plane Lounge;

	Party Temp;

	int AlfaQueue = 0;
	int BravoQueue = 0;
	int	LoungeQueue = 0;
	int i = 0;

		// MAIN MENU
		cout << "Welcome to The Tree Top Airways Ticketing System" << endl;

		cout << "\n/---------------Avilable Commands---------------\\" << endl;
		cout << "| ALFA		<size>				|" << endl;
		cout << "| BRAVO		<size>				|" << endl;
		cout << "| LOUNGE	<size>				|" << endl;
		cout << "| FLY		<size>				|" << endl;
		cout << "| ARRIVE	<airplane> <partyName> <size>	|" << endl;
		cout << "| SHUTDOWN					|" << endl;
		cout << "\\-----------------------------------------------/" << endl;

		do {
		cout << "\n>";

		menuOption = ReadCommand();

		switch (menuOption) {	// Commands
		case CmdAlfa:	// Initalize Alfa
			if (InitAlfa) {
				cout << "You already set up Alfa" << endl;
				ReadInteger();
			}
			else
			{
				Alfa.NumSeats = ReadInteger();
				Alfa.NumParties = 0;
				Alfa.NumEmptySeats = Alfa.NumSeats;
				Alfa.Parties = new Party[Alfa.NumSeats];
				InitAlfa = true;
				cout << "Plane Alfa has been set to " << Alfa.NumSeats << " avilable seats." << endl;
			}
			break;
		case CmdBravo:	// Initalize Bravo
			if (InitBravo) {
				cout << "You already set up Bravo" << endl;
				ReadInteger();
			}
			else
			{
				Bravo.NumSeats = ReadInteger();
				Bravo.NumParties = 0;
				Bravo.NumEmptySeats = Bravo.NumSeats;
				Bravo.Parties = new Party[Bravo.NumSeats];
				InitBravo = true;
				cout << "Plane Bravo has been set to " << Bravo.NumSeats << " avilable seats." << endl;
			}
			break;
		case CmdLounge:	// Initalize Lounge
			if (InitLounge) {
				cout << "You already set up the Lounge" << endl;
				ReadInteger();
			}
			else
			{
				Lounge.NumSeats = ReadInteger();
				Lounge.NumParties = 0;
				Lounge.NumEmptySeats = Lounge.NumSeats;
				Lounge.Parties = new Party[Lounge.NumSeats];
				InitLounge = true;
				cout << "The lounge has been set to " << Lounge.NumSeats << " avilable seats." << endl;
			}
			break;
		case CmdArrive:	// Ticketing Process
			if ((!InitAlfa) || (!InitBravo) || (!InitLounge)) {
				cout << "Not available, system has not been initialized" << endl;
				Temp.WhichPlane = ReadPlane();
				Temp.Name = ReadString();
				Temp.Size = ReadInteger();
			}
			else
			{
				Temp.WhichPlane = ReadPlane();
				Temp.Name = ReadString();
				Temp.Size = ReadInteger();

				if (Temp.WhichPlane == PlaneAlfa) { // TICKETING FOR ALFA
					if (Alfa.NumSeats < Temp.Size) {	// Is the plane large enough to ever accomadate this party?
						cout << "Sorry! Not enough room on the plane for a party that large." << endl;
					}
					else if (Alfa.NumEmptySeats >= Temp.Size) {	// Is there enough empty seats on the plane for this party?
						Alfa.NumEmptySeats = Alfa.NumEmptySeats - Temp.Size;
						Alfa.NumParties++;
						Alfa.Parties[AlfaQueue] = Temp;
						AlfaQueue++;

						if (Alfa.NumEmptySeats == 0) {	// If the plane is full, go ahead and send it off.
							cout << "There is enough room and the plane will take off as soon as they board." << endl;
							cout << "\n\t/*/ALPHA IS FILLED PREPARING FOR TAKEOFF\\*\\" << endl;
							Fly(PlaneAlfa, Alfa, Lounge);
							LoungeQueue = LoungeQueue - Alfa.NumParties;
							AlfaQueue = 0;
						}
						else
							cout << "There is enough room on the plane, they can now board. There are " << Alfa.NumEmptySeats << " seats left." << endl;
					}
					else if (Lounge.NumEmptySeats >= Temp.Size) {	// Is there enough room in the lounge?
						cout << "Have the party wait for the next flight in the lounge." << endl;
						Lounge.NumEmptySeats = Lounge.NumEmptySeats - Temp.Size;
						Lounge.NumParties++;
						Lounge.Parties[LoungeQueue] = Temp;
						LoungeQueue++;
					}
					else { // No Room on the plane or lounge
						cout << "We can not accomodate this party as of now! Have the customer try again later/tomorrow." << endl;
					}
				}

				if (Temp.WhichPlane == PlaneBravo) { // TICKETING FOR BRAVO
					if (Bravo.NumSeats < Temp.Size) {	// Is the plane large enough to ever accomadate this party?
						cout << "Sorry! Not enough room on the plane for a party that large." << endl;
					}
					else if (Bravo.NumEmptySeats >= Temp.Size) {	// Is there enough empty seats on the plane for this party?
						Bravo.NumEmptySeats = Bravo.NumEmptySeats - Temp.Size;
						Bravo.NumParties++;
						Bravo.Parties[BravoQueue] = Temp;
						BravoQueue++;

						if (Bravo.NumEmptySeats == 0) {	// If the plane is full, go ahead and send it off.
							cout << "There is enough room and the plane will take off as soon as they board." << endl;
							cout << "\n\t/*/BRAVO IS FILLED PREPARING FOR TAKEOFF\\*\\" << endl;
							Fly(PlaneBravo, Bravo, Lounge);
							LoungeQueue = LoungeQueue - Bravo.NumParties;
							BravoQueue = 0;
						}
						else
							cout << "There is enough room on the plane, they can now board. There are " << Bravo.NumEmptySeats << " seats left." << endl;
					}
					else if (Lounge.NumEmptySeats >= Temp.Size) {	// Is there enough room in the lounge?
						cout << "Have the party wait for the next flight in the lounge." << endl;
						Lounge.NumEmptySeats = Lounge.NumEmptySeats - Temp.Size;
						Lounge.NumParties++;
						Lounge.Parties[LoungeQueue] = Temp;
						LoungeQueue++;
					}
					else { // No Room on the plane or lounge
						cout << "We can not accomodate this party as of now! Have the customer try again later/tomorrow." << endl;
					}
				}

				if (Temp.WhichPlane == PlaneBad) {
					cout << "ERROR: Unknown plane" << endl;
				}
				break;
		case CmdFly:	// Manual Fly
			if ((!InitAlfa) || (!InitBravo) || (!InitLounge)) {
				cout << "Not available, system has not been initialized" << endl;
				ReadPlane();
			}
			else
			{
				switch (ReadPlane()) {
				case PlaneAlfa:
					Fly(PlaneAlfa, Alfa, Lounge);
					LoungeQueue = LoungeQueue - Alfa.NumParties;
					AlfaQueue = 0;
					break;
				case PlaneBravo:
					Fly(PlaneBravo, Bravo, Lounge);
					LoungeQueue = LoungeQueue - Bravo.NumParties;
					BravoQueue = 0;
					break;
				case PlaneBad:
					cout << "ERROR: Unknown plane" << endl;
					break;
				default:
					cout << "Internal error 102, please contact customer support" << endl;
					exit(0);
					break;
				}
			}
			break;
		case CmdShutdown:	// Exit
			if ((InitAlfa) && (InitBravo) && (InitLounge)) {
				while (Lounge.NumParties != 0) {
					Fly(PlaneAlfa, Alfa, Lounge);
					LoungeQueue = LoungeQueue - Alfa.NumParties;
					AlfaQueue = 0;
					Fly(PlaneBravo, Bravo, Lounge);
					LoungeQueue = LoungeQueue - Bravo.NumParties;
					BravoQueue = 0;
				}
			}
			cout << "Shutting Down... ";
			shutdown = true;
			break;
		default:
			cout << "There was an error reading your command, please contact your system administrator." << endl;
			break;
			}
		}
	} while (!shutdown);
}