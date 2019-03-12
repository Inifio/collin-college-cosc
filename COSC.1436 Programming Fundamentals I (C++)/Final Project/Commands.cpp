#include <string.h>

#include "Commands.h"
#include "ReadString.h"

char *	CommandWords[] = {
	"Alfa",
	"Bravo",
	"Lounge",
	"Arrive",
	"Fly",
	"Shutdown"
};

Commands ReadCommand()
{
	char *		Command;
	Commands	Cmd;

	Command = ReadString();
	for (Cmd = CmdAlfa; Cmd < CmdBad; Cmd = (Commands)(Cmd + 1))
		if (_strcmpi(Command, CommandWords[Cmd]) == 0)
		{
			delete[] Command;
			return Cmd;
		}
		else;
	for (Cmd = CmdBravo; Cmd < CmdBad; Cmd = (Commands)(Cmd + 1))
		if (_strcmpi(Command, CommandWords[Cmd]) == 0)
		{
			delete[] Command;
			return Cmd;
		}
		else;
	for (Cmd = CmdLounge; Cmd < CmdBad; Cmd = (Commands)(Cmd + 1))
		if (_strcmpi(Command, CommandWords[Cmd]) == 0)
		{
			delete[] Command;
			return Cmd;
		}
		else;
	for (Cmd = CmdShutdown; Cmd < CmdBad; Cmd = (Commands)(Cmd + 1))
		if (_strcmpi(Command, CommandWords[Cmd]) == 0)
		{
			delete[] Command;
			return Cmd;
		}
		else;

		delete[] Command;
		return CmdBad;
}