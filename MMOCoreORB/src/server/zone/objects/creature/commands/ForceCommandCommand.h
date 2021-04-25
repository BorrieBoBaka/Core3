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
		ManagedReference<SceneObject*> object;
		ManagedReference<CreatureObject*> creo;
		StringTokenizer args(arguments.toString());

		if (target != 0) {
			object = server->getZoneServer()->getObject(target, false);
		}

		String command, subCommand, subSubCommand;
		if (args.hasMoreTokens()) {
			args.getStringToken(command);
		}

		command = command.toLowerCase();

		if (command == "test") {
			BorDev::SendHelloWorld(creature);
		} else if (command == "combat") {
			if (object != nullptr) {
				if (object->isCreatureObject()) {
					BorDev::ToggleCombat(object->asCreatureObject());
				} else {
					BorDev::ToggleCombat(creature);
				}
			} else {
				BorDev::ToggleCombat(creature);
			}
			
		} else if (command == "goto") {
			BorDev::creatureGoto(creature, target);
		} else if (command == "follow") {
			BorDev::creatureFollow(creature, target);
		} else if (command == "stay") {
			BorDev::creatureStay(creature, target);
		} else if (command == "ai") {
			if (object->isCreatureObject()) {
				BorDev::ToggleAlwaysOnAI(object->asCreatureObject(), creature);
			}
		}

		

		return SUCCESS;
	}

};

#endif //FORCECOMMANDCOMMAND_H_
