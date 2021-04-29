/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef DMCOMMAND_H_
#define DMCOMMAND_H_

class DmCommand : public QueueCommand {

public:
	DmCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
