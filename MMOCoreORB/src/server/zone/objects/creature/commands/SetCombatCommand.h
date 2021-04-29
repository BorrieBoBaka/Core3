/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef SETCOMBATCOMMAND_H_
#define SETCOMBATCOMMAND_H_

class SetCombatCommand : public QueueCommand {

public:
	SetCombatCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
