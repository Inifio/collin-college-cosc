#ifndef COMMANDS_H
#define COMMANDS_H

enum Commands {
	CmdAlfa,
	CmdBravo,
	CmdLounge,
	CmdArrive,
	CmdFly,
	CmdShutdown,

	CmdBad
};

Commands ReadCommand();

#endif