/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef FORCECOMMANDCOMMAND_H_
#define FORCECOMMANDCOMMAND_H_

#include "server/zone/borrie/BorDev.h"

class ForceCommandCommand : public QueueCommand {
public:

	ForceCommandCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();
		StringTokenizer args(arguments.toString());

		String command, subCommand, subSubCommand;
		if (args.hasMoreTokens()) {
			args.getStringToken(command);
		}

		command = command.toLowerCase();

		if (command == "test") {
			BorDev::SendHelloWorld(creature);
		}

		

		return SUCCESS;
	}

};

#endif //FORCECOMMANDCOMMAND_H_
