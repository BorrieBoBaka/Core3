/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef NTARGETCOMMAND_H_
#define NTARGETCOMMAND_H_

class NTargetCommand : public QueueCommand {

public:
	NTargetCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
