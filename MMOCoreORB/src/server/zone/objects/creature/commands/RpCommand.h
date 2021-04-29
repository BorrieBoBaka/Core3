/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef RPCOMMAND_H_
#define RPCOMMAND_H_

class RpCommand : public QueueCommand {

public:
	RpCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
